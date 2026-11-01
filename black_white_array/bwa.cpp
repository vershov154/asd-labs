#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

class BlackWhiteArray {
private:
    size_t max_rank;       // максимально допустимый ранг сегментов в структуре
    size_t total_capacity; // суммарное выделенное количество ячеек типа int

    std::vector<int> memory_pool; // единый пул памяти. Все сегменты лежат друг за другом.
    size_t white_zone_offset;
    size_t black_zone_offset;

    std::vector<bool> white_filled;
    std::vector<bool> black_filled;

    /**
     * вспомогательный приватный метод для расчета точного адреса в пуле
     * is_black – сегмент в Чёрной зоне (true) или в Белой (false)?
     * rank – ранг сегмента (от 0 до max_rank)
     * Физический индекс первой ячейки нужного сегмента внутри memory_pool
     */

     size_t get_segment_index(bool is_black, size_t rank) const {
        // размер любого сегмента ранга R равен 2^R
        // чтобы найти начало сегмента, нужно сложить размеры всех предыдущих: 
        // 2^0 + 2^1 + 2^2 + ... + 2^(R-1) – эта сумма равна (2^R) - 1
        
        // 1ULL << rank – это операция побитового сдвига, которая вычисляет 2^rank (pow – долго)
        // ULL (Unsigned Long Long) гарантируют защиту от переполнения
        size_t internal_offset = (1ULL << rank) - 1;
        
        // возвращаем базовый адрес зоны + сдвиг внутри этой зоны
        if (is_black) {
            return black_zone_offset + internal_offset;
        } else {
            return white_zone_offset + internal_offset;
        }
    }

public:
    BlackWhiteArray(size_t max_r = 5) : max_rank(max_r) { // 5 по умолчанию
        // вместимость Белой зоны – это сумма всех сегментов от 0 до max_rank включительно
        // 2^(max_rank + 1) - 1
        size_t white_size = (1ULL << (max_rank + 1)) - 1; 
        
        // вместимость Чёрной зоны в два раза меньше, тк не включает в сеюя максимальный ранг
        // 2^max_rank - 1
        size_t black_size = (1ULL << max_rank) - 1;
        
        total_capacity = white_size + black_size; // общий размер
        
        // ВЫДЕЛЯЕМ ОПЕРАТИВНУЮ ПАМЯТЬ ОДИН РАЗ НА ВСЮ ЖИЗНЬ ОБЪЕКТА
        memory_pool.resize(total_capacity, 0);

        white_zone_offset = 0;          // белая зона занимает начало массива
        black_zone_offset = white_size; // чёрная зона скромно начинается сразу за Белой

        // выделяем память под массивы флагов занятости
        // размер равен (max_rank + 1), изначально все флаги выставляем в false (пусто)
        white_filled.resize(max_rank + 1, false);
        // Черная зона содержит сегменты от 0 до max_rank - 1
        black_filled.resize(max_rank, false);
    }

    /** 
    * метод вставки нового числа в структуру данных
    * value – целое число, которое мы хотим сохранить
    */
    void insert(int value) {
        std::cout << "[Insert] Attempting to add value: " << value << "\n";
        
        // буфер carry изначально хранит наше новое число
        std::vector<int> carry = { value };
        size_t current_rank = 0;

        while (current_rank <= max_rank) {
            size_t seg_size = (1ULL << current_rank); 

            // СЛУЧАЙ 1: Белый сегмент текущего ранга свободен
            if (!white_filled[current_rank]) {
                size_t dest_idx = get_segment_index(false, current_rank);
                std::copy(carry.begin(), carry.end(), memory_pool.begin() + dest_idx);
                white_filled[current_rank] = true; 
                std::cout << " -> Successfully written to White segment of rank " << current_rank << "\n";
                break;
            }
            // СЛУЧАЙ 2: Белый занят, но Чёрный сегмент свободен
            else if (current_rank < max_rank && !black_filled[current_rank]) {
                size_t dest_idx = get_segment_index(true, current_rank);
                std::copy(carry.begin(), carry.end(), memory_pool.begin() + dest_idx);
                black_filled[current_rank] = true; 
                std::cout << " -> Successfully written to Black segment of rank " << current_rank << "\n";
                break;
            }
            // СЛУЧАЙ 3: Переполнение! И Белый, и Чёрный сегменты заняты
            else {
                if (current_rank == max_rank) {
                    throw std::runtime_error(" !! Structure Overflow! No space left in BlackWhiteArray.");
                }

                std::cout << " !! Out of space at rank " << current_rank << ". Launching cascading merge...\n";
                
                size_t w_idx = get_segment_index(false, current_rank);
                size_t b_idx = get_segment_index(true, current_rank);
                
                // создаем следующий carry строго правильного размера (seg_size * 2)
                std::vector<int> next_carry(seg_size * 2);
                
                // сливаем то, что уже лежало на этом уровне (Белый + Чёрный)
                std::merge(memory_pool.begin() + w_idx, memory_pool.begin() + w_idx + seg_size,
                           memory_pool.begin() + b_idx, memory_pool.begin() + b_idx + seg_size,
                           next_carry.begin());

                white_filled[current_rank] = false;
                black_filled[current_rank] = false;
                
                // старый carry записываем в только что освободившийся Белый сегмент текущего ранга
                size_t dest_idx = get_segment_index(false, current_rank);
                std::copy(carry.begin(), carry.end(), memory_pool.begin() + dest_idx);
                white_filled[current_rank] = true;
                
                std::cout << " -> Kept previous carry at White segment of rank " << current_rank << "\n";
                
                // на ранг выше отправляем идеально отсортированную пару Белого и Чёрного (next_carry)
                carry = std::move(next_carry);  
                current_rank++;
            }
        }
    }




    /** 
     * Поиск элемента в структуре данных
     * Благодаря тому, что каждый активный сегмент ВСЕГДА отсортирован, мы можем использовать бинарный поиск
     * target – число, которое мы ищем
     */
    bool search(int target) const {
        // обходим абсолютно все ранги с нуля до максимального
        for (size_t r = 0; r <= max_rank; ++r) {
            size_t seg_size = (1ULL << r); // размер сегментов на текущем ранге r

            if (white_filled[r]) {
                size_t idx = get_segment_index(false, r); // находим его место в пуле
                // std::binary_search выполняет классический двоичный поиск
                if (std::binary_search(memory_pool.begin() + idx, memory_pool.begin() + idx + seg_size, target)) {
                    return true;
                }
            }
        
            // обход Чёрной зоны (только для рангов < max_rank)
            if (r < max_rank && black_filled[r]) {
                size_t idx = get_segment_index(true, r); // находим его место в пуле
            
                if (std::binary_search(memory_pool.begin() + idx, memory_pool.begin() + idx + seg_size, target)) {
                    return true;
                }
            }
        }
    
        return false;
    }

    /**
     * Метод визуализации внутренней структуры Black-White Array.
     */
    void print_structure() const {
        std::cout << "\n================ CURRENT BWA STATE ================\n";
        for (size_t r = 0; r <= max_rank; ++r) {
            size_t seg_size = (1ULL << r);
            std::cout << "Rank " << r << " (Size " << seg_size << ") | ";
            
            std::cout << "White: ";
            if (white_filled[r]) {
                size_t idx = get_segment_index(false, r);
                std::cout << "[ ";
                for (size_t i = 0; i < seg_size; ++i) {
                    std::cout << memory_pool[idx + i] << " ";
                }
                std::cout << "] ";
            } else {
                std::cout << "[ Empty ] ";
            }

            std::cout << "| Black: ";
            if (r < max_rank) {
                if (black_filled[r]) {
                    size_t idx = get_segment_index(true, r);
                    std::cout << "[ ";
                    for (size_t i = 0; i < seg_size; ++i) {
                        std::cout << memory_pool[idx + i] << " ";
                    }
                    std::cout << "]";
                } else {
                    std::cout << "[ Empty ]";
                }
            } else {
                std::cout << "[ None ]"; // на максимальном ранге Чёрной зоны физически нет
            }
            std::cout << "\n";
        }
        std::cout << "===================================================\n\n";
    }


    // вспомогательный геттер для демонстрации размера пула
    size_t get_total_capacity() const { return total_capacity; }
};

int main() {
    std::cout << "=== Welcome to Black-White Array Manager ===\n";
    std::cout << "Enter maximum rank for the structure (e.g., 3, 4, 5): ";
    size_t user_max_rank;

    if (!(std::cin >> user_max_rank)) {
        std::cout << "Invalid input. Using default max_rank = 4.\n";
        user_max_rank = 4;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    BlackWhiteArray bwa(user_max_rank);
    std::cout << "Structure initialized. Total allocated int cells: " << bwa.get_total_capacity() << "\n\n";
    int choice = 0;
    while (true) {
        std::cout << "--- MENU ---\n";
        std::cout << "1. Insert element\n";
        std::cout << "2. Search element\n";
        std::cout << "3. Print current structure\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Please enter a valid number.\n\n";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        if (choice == 1) {
            int val;
            std::cout << "Enter integer to insert: ";
            if (std::cin >> val) {
            try {
                bwa.insert(val);
            } catch (const std::exception& e) {
                std::cerr << e.what() << "\n";
                }
            } else {
                std::cout << "Invalid integer.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        else if (choice == 2) {
            int target;
            std::cout << "Enter integer to search: ";
            if (std::cin >> target) {
                if (bwa.search(target)) {
                std::cout << " >> FOUND: Element " << target << " exists in BWA!\n";
                } else {
                    std::cout << " >> NOT FOUND: Element " << target << " is not in BWA.\n";
                }
            } else {
                std::cout << "Invalid integer.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
        else if (choice == 3) {
            bwa.print_structure();
        }
        else if (choice == 4) {
            std::cout << "Exiting. Goodbye!\n";
            break;
        }
        else {
            std::cout << "Unknown choice. Try again.\n";
        }
    std::cout << "\n";
    }
    return 0;
}