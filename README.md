# BSU_OS_collocvium_Vlasenko_10

ВЛАСЕНКО ВИКТОРИЯ 10 ГРУППА 
1. WinAPI для лабораторной работы №3 (потоки, синхронизация)
В лабораторной работе №3 (управление потоками и синхронизация) использовались следующие функции WinAPI:
Создание и управление потоками:
CreateThread() – создает новый поток.  HANDLE CreateThread(
    LPSECURITY_ATTRIBUTES lpThreadAttributes,
    SIZE_T dwStackSize,
    LPTHREAD_START_ROUTINE lpStartAddress,
    LPVOID lpParameter,
    DWORD dwCreationFlags,
    LPDWORD lpThreadId
);  Пример: DWORD WINAPI ThreadFunc(LPVOID lpParam) {
    printf("Thread running\n");
    return 0;
}

HANDLE hThread = CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL); 
WaitForSingleObject() – ожидает завершения потока. WaitForSingleObject(hThread, INFINITE);
CloseHandle(hThread); 
Синхронизация:
Мьютекс (CreateMutex(), ReleaseMutex()) HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);
WaitForSingleObject(hMutex, INFINITE); // Захват мьютекса
// Критическая секция
ReleaseMutex(hMutex); // Освобождение 

Событие (CreateEvent(), SetEvent(), ResetEvent())  HANDLE hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
SetEvent(hEvent); // Сигнал о готовности
WaitForSingleObject(hEvent, INFINITE); // Ожидание события 
Критические секции (InitializeCriticalSection(), EnterCriticalSection(), LeaveCriticalSection()) CRITICAL_SECTION cs;
InitializeCriticalSection(&cs);
EnterCriticalSection(&cs);
// Критическая секция
LeaveCriticalSection(&cs);
DeleteCriticalSection(&cs); 

2. Что такое поток в ОС Windows?
Поток (thread) – это наименьшая единица выполнения в процессе. В Windows каждый процесс имеет хотя бы один поток (главный), но может создавать дополнительные.
Характеристики потока:
Имеет собственный стек, регистры и счетчик команд.
Разделяет память и ресурсы процесса с другими потоками.
Планируется ОС независимо от других потоков.
Пример создания потока в Windows:
DWORD WINAPI MyThread(LPVOID param) {
    printf("Hello from thread!\n");
    return 0;
}

int main() {
    HANDLE hThread = CreateThread(NULL, 0, MyThread, NULL, 0, NULL);
    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);
    return 0;
}

3. Что такое мьютекс?
Мьютекс (Mutex, Mutual Exclusion) – объект синхронизации, который предотвращает одновременный доступ нескольких потоков к общему ресурсу.
Свойства мьютекса:
Только один поток может владеть мьютексом в данный момент.
Если мьютекс занят, другие потоки блокируются до его освобождения.
В Windows используется CreateMutex(), WaitForSingleObject(), ReleaseMutex().
Пример:
cpp
Copy
HANDLE hMutex = CreateMutex(NULL, FALSE, NULL);

DWORD WINAPI ThreadFunc(LPVOID lpParam) {
    WaitForSingleObject(hMutex, INFINITE);
    printf("Thread %d entered critical section\n", GetCurrentThreadId());
    Sleep(1000); // Имитация работы
    ReleaseMutex(hMutex);
    return 0;
}

4. Что такое событие (Event)?
Событие (Event) – объект синхронизации, который позволяет потокам ожидать сигнала от других потоков.
Типы событий:
Автосброс (auto-reset) – автоматически сбрасывается после пробуждения одного потока.
Ручной сброс (manual-reset) – требует явного сброса (ResetEvent()).
Пример:

HANDLE hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

// Поток 1: ждет событие
WaitForSingleObject(hEvent, INFINITE);
printf("Event signaled!\n");

// Поток 2: устанавливает событие
SetEvent(hEvent);

5. Сравнение C++98 и C++11/17/20 (в контексте лабораторных)

Пример C++11:
#include <thread>
#include <mutex>
#include <iostream>

std::mutex mtx;

void thread_func() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t1(thread_func);
    std::thread t2(thread_func);
    t1.join();
    t2.join();
    return 0;
}
Вывод:
C++98 требовал WinAPI для многопоточности.
C++11+ ввел стандартные потоки и синхронизацию, что сделало код кроссплатформенным.
C++17/20 добавили std::jthread, std::atomic_ref и другие улучшения.

Итог
WinAPI для потоков: CreateThread, WaitForSingleObject.
Поток – минимальная единица выполнения в процессе.
Мьютекс – блокирует доступ к ресурсу.
Событие – сигнализирует о состоянии.
C++11+ заменил WinAPI на <thread>, <mutex>, <atomic>.

1. Что такое ООП? (Объектно-Ориентированное Программирование)
Определение: ООП — парадигма программирования, основанная на концепции "объектов", которые объединяют данные (поля) и методы (функции) для их обработки. Основные принципы:
Инкапсуляция – скрытие внутренней реализации (например, private-поля в классе).
Наследование – создание новых классов на основе существующих (class Dog : public Animal).
Полиморфизм – возможность объектов вести себя по-разному в зависимости от контекста (перегрузка методов, виртуальные функции).
Абстракция – упрощение сложных систем через моделирование классов (например, Car вместо отдельных деталей двигателя).
Пример из лабораторной работы:
 
class ThreadManager {
private:
    std::vector<std::thread> threads; // Инкапсуляция
public:
    void addThread(std::function<void()> task) {
        threads.emplace_back(task); // Полиморфизм (лямбда/функция)
    }
    ~ThreadManager() {
        for (auto& t : threads) t.join();
    }
};

2. Магическое число 7 ± 2 Миллера
Теория: Человек может одновременно удерживать в оперативной памяти 7±2 элемента.
Примеры из IT:
Лимит вкладок в браузере – большинство пользователей открывают ≤7 вкладок.
Меню навигации – сайты редко используют >7 пунктов (например, GitHub: Pull requests, Issues, Marketplace и т.д.).
Аргументы функции – рекомендация: не более 7 параметров (void draw(int x, int y, int w, int h, Color c, bool fill)).
Цветовые палитры – стандартные схемы (Material Design) содержат ~7 основных цветов.
Ограничение уровней вложенности – код с if (a && b || c && ...) становится нечитаемым после 7 условий.
Длина строки кода – рекомендация: ≤80 символов (примерно 7–10 слов).
Число пунктов в CLI-интерфейсе – например, git имеет 7 базовых команд (commit, push, pull и т.д.).

3. Энтропия ПО
Определение: Мера хаоса в коде — рост сложности и беспорядка при разработке.
Антиэнтропийные меры:
Рефакторинг – устранение "копипасты" (например, замена дублирующегося кода на функцию).
Модульность – разбиение на классы/компоненты (лабораторная с потоками: ThreadPool, MutexManager).
Документация – комментарии и README (описание структур данных в лабораторной по синхронизации).
Тестирование – юнит-тесты для критических участков (тесты для lock-free алгоритмов).
CI/CD – автоматическая сборка и проверка (например, GitHub Actions для лабораторных).
Пример энтропии:
 
// Плохо (высокая энтропия):
if (a) { b = c + d; } else { b = c - d; }  
// Хорошо (низкая энтропия):
b = a ? c + d : c - d;

4. 5 признаков сложной системы по Гради Бучу
Иерархичность
Пример 1: В лабораторной по потокам —
 MainThread → WorkerThreads → TaskQueue.
Пример 2: В проекте с GUI — Window → Panel → Button → EventHandler.
Наличие обратных связей
Пример 1: Поток A ждет мьютекс от потока B, который ждет ресурс от A (deadlock).
Пример 2: Callback-функция в обработчике событий (button.onClick → updateUI → button.disable).
Эмерджентность (неочевидные свойства системы)
Пример 1: В pet-проекте с нейросетью — неожиданное поведение при обучении на специфичных данных.
Пример 2: В лабораторной по многопоточности — race condition, который проявляется только при высокой нагрузке.
Адаптивность
Пример 1: Динамическое создание потоков в ThreadPool в зависимости от нагрузки.
Пример 2: Плагинная архитектура (например, загрузка модулей .dll в лабораторной по IPC).
Неопределенность
Пример 1: В проекте с сокетами — обработка разрыва соединения.
Пример 2: В лабораторной по файловому менеджеру — реакция на отсутствие прав доступа.

5. Закон иерархических компенсаций Седова
Формулировка: Рост сложности системы компенсируется созданием иерархических уровней управления.
Примеры из IT:
Переход от монолитов к микросервисам – разбиение сложного приложения на независимые сервисы (например, Amazon в 2000-х).
Появление ОС – управление ресурсами ЭВМ через абстракции (файлы, процессы).
Слоистая архитектура ПО – MVC (Model-View-Controller) в веб-разработке.
Виртуализация – гипервизоры для управления множеством ВМ.
Контейнеризация – Docker как способ изоляции сервисов.
Пример из лабораторной: В проекте с многопоточным сервером:
Уровень 1: Потоки (accept()).
Уровень 2: Пулы потоков (ThreadPool).
Уровень 3: Менеджер задач (TaskQueue).

