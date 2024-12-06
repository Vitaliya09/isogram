#include "isogram.hpp"
#include <set>
#include <locale>


std::locale locale{""};

auto is_isogram(std::string const& word) -> bool {
    // Функция is_isogram получает на вход строку word
    // Возвращает true, если строка является изограммой,
    // и false, если не является
    
    if (word.empty()) { // Проверяем, пуста ли строка
        return true; // Пустая строка считается изограммой
    }

    std::set<char> seen_characters; // Множество для уникальных букв
    
    for (char ch : word) { // Перебор каждого символа строки
        if (std::isalpha(ch, locale)) { // Если символ является буквой
            char lower_ch = std::tolower(ch, locale); // Преобразуем в нижний регистр
            if (seen_characters.count(lower_ch)) { // Проверяем, есть ли уже буква в множестве
                return false; // Если буква уже встречалась, строка не изограмма
            }
            seen_characters.insert(lower_ch); // Добавляем букву в множество
        }
    }
    
    return true; // Если не найдено повторяющихся букв, строка — изограмма
}
