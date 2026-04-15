*This project has been created as part of the 42 curriculum by \<smedenec\>.*

# Philosophers  
A multithreaded simulation of the classic Dining Philosophers problem.

---

## 🧩 Description

The **Philosophers** project is an introduction to multithreading, synchronization, and concurrency control in C.  
Its goal is to simulate a group of philosophers sitting around a table, alternating between **thinking**, **eating**, and **sleeping**, while sharing a limited number of forks.

The challenge lies in preventing:

- **deadlocks** (all philosophers waiting forever),  
- **race conditions** (inconsistent shared data),  
- **incorrect timing** (actions must respect precise millisecond delays),  
- **unsynchronized output** (messages must never overlap or appear after a philosopher dies).

The project uses:

- **POSIX threads (pthreads)**  
- **mutexes** for synchronization  
- **precise time management**  
- **thread-safe printing**  
- **a monitoring thread** to detect starvation  

The simulation ends when:

1. A philosopher dies (fails to eat within `time_to_die`), or  
2. All philosophers have eaten at least `must_eat` times (if provided).

---

## ⚙️ Instructions

### ✔️ Compilation

Run:

```bash
make
```

This will compile the program and produce the philo executable.

To clean object files:

```bash
make clean
```

To remove everything:

```bash
make fclean
```

To recompile from scratch:

```bash
make re
```

### ✔️ Execution

The program must be executed with the following arguments:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat]
```
Parameters:

    number_of_philosophers — number of philosophers and forks

    time_to_die — max time (ms) a philosopher can go without eating

    time_to_eat — time (ms) spent eating

    time_to_sleep — time (ms) spent sleeping

    must_eat (optional) — number of meals required before stopping

Example:

```bash
./philo 5 800 200 200
```
or with a meal limit:

```bash
./philo 5 800 200 200
```

### Example Output

```bash
0 1 has taken a fork
0 1 has taken a fork
1 1 is eating
2 3 has taken a fork
2 3 has taken a fork
3 3 is eating
500 6 died
```

The first number is the timestamp in milliseconds since the start.

The second number is the philosopher ID.

The message describes the action.

No message is printed after a death, as required by the subject.

Technical Notes
✔️ Thread Model

    One thread per philosopher

    One monitoring thread to detect starvation

✔️ Synchronization

    One mutex per fork

    One mutex per philosopher to protect meal timestamps

    One global mutex for printing

    Shared dead flag to stop all threads safely

✔️ Timing

    Custom ft_usleep() to avoid blocking the death checker

    Millisecond-accurate timestamps using gettimeofday()

✔️ Deadlock Avoidance

    Philosophers take forks in a controlled order

    Odd/even strategy or staggered start to prevent circular waiting

References

    Dijkstra’s Dining Philosophers Problem

    POSIX Threads documentation

    Mutexes and condition variables (IEEE / POSIX)

    “Operating Systems: Three Easy Pieces” — concurrency chapters

    GNU man pthread_create, man pthread_mutex_lock, man gettimeofday

AI Usage Disclosure

AI assistance (Microsoft Copilot) was used for:

    Clarifying multithreading concepts

    Debugging race conditions and mutex usage

    Improving code readability and structure

    Writing and refining this README

    Validating the logic of the death checker and print synchronization

    Ensuring compliance with the 42 project requirements

All code was written, tested, and validated manually.
AI was used as a support tool, not as a code generator.


The program strictly follows the rule: no output after a philosopher dies.

All timing is relative to the simulation start.

The implementation avoids undefined behavior and ensures thread-safe access to shared data.