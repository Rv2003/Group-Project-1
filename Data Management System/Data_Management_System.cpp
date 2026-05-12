#include <iostream>
#include <iomanip>
#include <windows.h>
#include <string>
#include "Header.h"

using namespace std;

void color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void titleScreen()
{
    color(11);

    cout << "\n";
    cout << " =========================================================\n";
    cout << "|                                                        |\n";
    cout << "|              MEMORY MANAGEMENT SIMULATOR               |\n";
    cout << "|                                                        |\n";
    cout << " =========================================================\n";

    color(14);

    cout << "\n  FEATURES\n\n";
    cout << "   [1] First Fit Allocation\n";
    cout << "   [2] Best Fit Allocation\n";
	cout << "   [3] Worst Fit Allocation\n";
    cout << "   [4] Compaction Free Blocks\n";
	cout << "   [5] Reset Back to Initial\n";
	cout << "   [6] Free Process\n";
    cout << "   [7] Dynamic Memory Visualization\n";

    color(7);
}

void memoryBox()
{
    color(10);

    cout << "\n";
    cout << " +------------------------------------------------------+\n";
    cout << " |              CURRENT MEMORY STATE                    |\n";
    cout << " +------------------------------------------------------+\n";

    color(7);
}

void mainMenu()
{
    color(13);

    cout << "\n";
    cout << " =========================================================\n";
    cout << "                    MAIN MENU                            \n";
    cout << " =========================================================\n";

    color(11);

    cout << "\n  [1] Start Simulation\n";
    cout << "  [2] Exit Program\n";

    color(14);
    cout << "\n ---------------------------------------------------------\n";

    color(7);
    cout << " Enter Choice : ";
}

void simulationMenu()
{
    color(9);

    cout << "\n";
    cout << " =========================================================\n";
    cout << "           MEMORY ALLOCATION AND MANAGEMENT METHODS                \n";
    cout << " =========================================================\n";

    color(10);

    cout << "\n  [1] Best Fit Allocation\n";
    cout << "  [2] First Fit Allocation\n";
    cout << "  [3] Worst Fit Allocation\n";
    cout << "  [4] Compaction Free Blocks\n";
    cout << "  [5] Reset Back to Initial\n";
	cout << "  [6] Free Process\n";
	cout << "  [7] Exit\n";

    color(14);
    cout << "\n ---------------------------------------------------------\n";

    color(7);
    cout << " Enter Choice : ";
}

void allocationWindow(string title)
{
    color(11);

    cout << "\n";
    cout << " +------------------------------------------------------+\n";
    cout << " | " << left << setw(52) << title << "|\n";
    cout << " +------------------------------------------------------+\n";

    color(7);
}

void loading()
{
    color(14);

    cout << "\nProcessing";

    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(300);
    }

    color(7);
}

int main()
{
    int option;
    bool quit = false;
    int memory;
    string process;

    singly_linked_list list;

    list.allocate_memory(1024, "FREE");
    list.allocate_memory(2048, "FREE");
    list.allocate_memory(3072, "B");
    list.allocate_memory(1048, "D");
    list.allocate_memory(800, "FREE");

    while (quit != true)
    {
        system("cls");

        titleScreen();

        memoryBox();
        list.display();

        mainMenu();
        cin >> option;

        if (option == 1)
        {
            system("cls");

            titleScreen();
            memoryBox();
            list.display();

            simulationMenu();
            cin >> option;

            if (option == 1)
            {
                system("cls");

                allocationWindow("BEST FIT ALLOCATION");

                cout << "\nEnter Memory Size : ";
                cin >> memory;

                cout << "Enter Process Name : ";
                cin >> process;

                loading();

                list.best_fit(process, memory);

                color(10);
                cout << "\n\nAllocation Successful!\n";

                color(7);
                system("pause");
            }
            else if (option == 2)
            {
                system("cls");

                allocationWindow("FIRST FIT ALLOCATION");

                cout << "\nEnter Memory Size : ";
                cin >> memory;

                cout << "Enter Process Name : ";
                cin >> process;

                loading();

                list.first_fit(process, memory);

                color(10);
                cout << "\n\nAllocation Successful!\n";

                color(7);
                system("pause");
            }
            else if (option == 3)
            {
                system("cls");

                allocationWindow("WORST FIT ALLOCATION");

                cout << "\nEnter Memory Size : ";
                cin >> memory;

                cout << "Enter Process Name : ";
                cin >> process;

                loading();

                list.worst_fit(process, memory);

                color(10);
                cout << "\n\nAllocation Successful!\n";

                color(7);
                system("pause");
            }


            else if (option == 4)
			{
				system("cls");

				allocationWindow("COMPACTING FREE BLOCKS");

				loading();

				list.coalescing();

				color(10);
				cout << "\n\nCompaction Successful!\n";

				color(7);
				system("pause");
			}

			 else if (option == 5) {
                list.reset();
            
            }

			 else if (option == 6) {
				system("cls");

				allocationWindow("FREE PROCESS");

				cout << "\nEnter Process Name to Free : ";
				cin >> process;

				loading();

				list.free_process(process);

				color(10);
				cout << "\n\nProcess Freed Successfully!\n";

				color(7);
				system("pause");
			}

            else if (option == 7)
            {
                quit = true;
            }
           
            else
            {
                color(12);
                cout << "\nInvalid Option!\n";
                color(7);
                system("pause");
            }
        }
        else if (option == 2)
        {
            quit = true;

            system("cls");

            color(11);

            cout << "\n";
            cout << " =========================================================\n";
            cout << "              THANK YOU FOR USING THE SYSTEM             \n";
            cout << " =========================================================\n";

            color(7);
        }
        else
        {
            color(12);
            cout << "\nInvalid Option!\n";
            color(7);
            system("pause");
        }
    }

    return 0;
}