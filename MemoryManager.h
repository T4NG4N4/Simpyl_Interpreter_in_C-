#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

class MemoryManager {
public:
    MemoryManager(int threshold = 100, int check_interval = 10);
    void monitor_memory(int command_count);

private:
    int memory_threshold;
    int check_interval;
    int get_memory_usage();
};

#endif // MEMORYMANAGER_H