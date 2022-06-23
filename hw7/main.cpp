#include<iostream>

using namespace std;

class MMmanger {
	private:
		int num_of_space;
		int *num_of_allocated_space;
		int *g_mem_usage;
		int *g_mem;
	public:
		MMmanger(int num) {
			num_of_space = num;
			g_mem = new int[num_of_space]();
			num_of_allocated_space = new int[num_of_space]();
			g_mem_usage = new int[num_of_space]();
		}
		
		int *calloc_MM(int size) {
			int start_address = -1, num_of_non_allocated_space = 0;
			for (int i = 0; i < num_of_space; i++) {
				int j = i;
				while (g_mem_usage[j] == 0 && num_of_non_allocated_space < size && j < num_of_space) {
					num_of_non_allocated_space++;
					j++;
				}
				if (num_of_non_allocated_space == size) {
					start_address = i;
					break;
				}
				i = j;
			}
			if (start_address == -1) {
				cout << "Capacity:" << num_of_non_allocated_space << " - ";
				for (int i = 0; i < num_of_space; i++) {
					cout << g_mem_usage[i];
				}
				cout << " <- Out of space: demand " << size << endl;
				return NULL;
			} else {
				int num_of_total_non_allocated_space = 0;
				for (int i = 0; i < size; i++) {
					g_mem_usage[start_address + i] = 1;
				}
				for (int i = 0; i < num_of_space; i++) {
					if(g_mem_usage[i] == 0) {
						num_of_total_non_allocated_space++;
					}
				}
				num_of_allocated_space[start_address] = size;
				cout << "Capacity:" << num_of_total_non_allocated_space << " - ";
				for (int i = 0; i < num_of_space; i++) {
					cout << g_mem_usage[i];
				}
				printf("\n");
				return &g_mem[start_address];
			}
		}
		
		void free_MM(int *p) {
			int num_of_total_non_allocated_space = 0;
			if (p == NULL) {
				for (int i = 0; i < num_of_space; i++) {
					if(g_mem_usage[i] == 0) {
						num_of_total_non_allocated_space++;
					}
				}
				cout << "Capacity:" << num_of_total_non_allocated_space << " - ";
				for (int i = 0; i < num_of_space; i++) {
					cout << g_mem_usage[i];
				}
				cout << endl;
				return;
			}

			int start_address = p - g_mem;
			for (int i = 0; i < num_of_allocated_space[start_address]; i++) {
				g_mem_usage[start_address + i] = 0;
			}
			num_of_allocated_space[start_address] = 0;

			for (int i = 0; i < num_of_space; i++) {
				if(g_mem_usage[i] == 0) {
					num_of_total_non_allocated_space++;
				}
			}
		cout << "Capacity:" << num_of_total_non_allocated_space << " - ";
			for (int i = 0; i < num_of_space; i++) {
				cout << g_mem_usage[i];
			}
			cout << endl;
		}
};

int main() {
    MMmanger mmer(10);
    int* p1 = mmer.calloc_MM(1);
    int* p2 = mmer.calloc_MM(2);
    int* p3 = mmer.calloc_MM(3);
    int* p4 = mmer.calloc_MM(4);
    mmer.free_MM(p1);
    mmer.free_MM(p2);
    int* p5 = mmer.calloc_MM(6);

    return 0;
}
