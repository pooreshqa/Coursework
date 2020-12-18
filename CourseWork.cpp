#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <string>
#include <fstream>
using namespace std;

void PW1()
{
    int answer;
    answer = 1;
    while (answer != 0) {
        cout << "\nWhat tasks do you wanna check? (Write task's number)\n";
        cout << "1. Print how much memory(in bytes) on your computer is allocated for various data types withand without specifiers;\n";
        cout << "2. Display the binary representation in memory (all digits) of an integer;\n";
        cout << "3. Display a binary representation in memory (all bits) of the float type;\n";
        cout << "4. Display a binary representation in memory (all digits) of the double type.\n";
        cout << "To exit, enter 0 \n";
        cin >> answer;
        system("CLS");

        switch (answer)
        {
        case (1):
            int a;
            short int b;
            long int c;
            float d;
            double e;
            long double f;
            char g;
            bool h;
            cout << "int: " << sizeof(a) << "; short int: " << sizeof(b) << "; long int: " << sizeof(c) << "; float: " << sizeof(d) << "; double: " << sizeof(e) << "; long double: " << sizeof(f) << "; char: " << sizeof(g) << "; bool: " << sizeof(h) << "\n";
            break;
        case (2):
            int toBin;
            int mask;
            mask = 1;
            int num[32];
            bool answer2;

            while (true) {
                cout << "\nEnter integer: \n";
                cin >> toBin;

                for (int i = 0; i < 32; i++) {
                    num[i] = toBin & mask ? 1 : 0;
                    toBin = toBin >> 1;
                }

                for (int i = 31; i >= 0; i--) {
                    if (i == 30)
                        cout << " ";
                    cout << num[i];
                }
                cout << "\nExit? 1/0";
                cin >> answer2;
                if (answer2) {
                    system("CLS");
                    break;
                }
            }
            break;
        case (3):
            int mask3;
            mask3 = 1;
            int num3[32];
            bool answer3;
            union {
                int tool;
                float toBin2;
            };
            while (true) {
                cout << "\nEnter float: \n";
                cin >> toBin2;
                for (int i = 0; i < 32; i++) {
                    num3[i] = tool & mask3 ? 1 : 0;
                    tool = tool >> 1;
                }
                for (int i = 31; i >= 0; i--) {

                    cout << num3[i];
                    if (i == 31 || i == 23) {
                        cout << " ";
                    }
                }
                cout << "\nExit? 1/0";
                cin >> answer3;
                if (answer3) {
                    system("CLS");
                    break;
                }
            }
            break;
        case (4):
            bool num4[64];
            bool answer4;
            int index;
            union {
                double toBin3;
                int tool2[2];
            };
            while (true) {
                cout << "\nEnter double: \n";
                cin >> toBin3;
                index = 0;

                for (int k = 0; k < 2; k++) {
                    for (int i = 0; i < 32; i++) {
                        num4[index] = 1 & tool2[k];
                        tool2[k] >>= 1;
                        index++;
                    }
                }
                for (int i = 63; i >= 0; i--) {

                    cout << num4[i];
                    if (i == 63 || i == 52) {
                        cout << " ";
                    }
                }
                cout << "\nExit? 1/0";
                cin >> answer4;
                if (answer4) {
                    system("CLS");
                    break;
                }
            }
            break;
        case (0):
            cout << "Have a nice day!\n";
            break;
        default:
            cout << "Oh, no! This task doesn't exist. Let's try again.\n";
            break;
        };
    }
}

void quicksort(int* arr, int  end, int begin) {
    int mid;
    int f = begin;
    int l = end;
    mid = arr[(f + l) / 2];
    while (f < l)
    {
        while (arr[f] < mid) f++;
        while (arr[l] > mid) l--;
        if (f <= l)
        {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) quicksort(arr, l, begin);
    if (f < end) quicksort(arr, end, f);
}

int binarySearch(int array[], int x, int low, int high) {

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == x)
            return mid;

        if (array[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}

void PW2()
{
    const int N = 100;
    int unsortArr[N];
    int arr[N];
    cout << "\nLet's make some array and sort it to realize other tasks\n";

    int answer;
    answer = 2;

    while (answer != 0) {
        cout << "\nTo make new array, enter 1\n";
        cout << "To exit, enter 0 \n";
        cin >> answer;
        system("CLS");

        switch (answer)
        {
        case (1):
        {
            // создаем рандомный массив из 100 чисел от -99 до 99
            for (int i = 0; i < N; i++) {
                unsortArr[i] = -99 + (rand() % 200);
            }

            for (int i = 0; i < N; ++i)
                arr[i] = unsortArr[i];

            // сортируем массив с помощью quick sort
            auto startQuick = std::chrono::high_resolution_clock::now();
            int end, begin;
            end = N - 1;
            begin = 0;
            quicksort(arr, end, begin);
            auto endQuick = std::chrono::high_resolution_clock::now();
            auto timeQuick = std::chrono::duration_cast<std::chrono::nanoseconds>(endQuick - startQuick);

            cout << "\nTime spent on sorting (nanoseconds): " << std::fixed << timeQuick.count() << endl;

            int answer2;
            answer2 = 9;

            while (answer2 != 0) {
                cout << "\nUnsorted array: \n";
                for (int i = 0; i < N; i++)
                    cout << unsortArr[i] << " ";

                cout << "\n\nSorted array: \n";
                for (int i = 0; i < N; i++)
                    cout << arr[i] << " ";

                cout << "\n\nWhat tasks do you wanna check? (Write task's number)\n";
                cout << "3. Find the maximum and minimum element of the array. Calculate the search time in sorted and unsorted arrays using the chrono library;\n";
                cout << "4. Output the average value of the maximum and minimum values. Print the indexes of all elements that are equal to this value, and their number.\n";
                cout << "5. Print the number of elements in the sorted array that are less than the number that is initialized by the user;\n";
                cout << "6. Print the number of elements in the sorted array that are greater than the number that is initialized by the user;\n";
                cout << "7. Output information about whether the number entered by the user is in the sorted array;\n";
                cout << "8. Swaps array elements whose indexes are entered by the user.\n";
                cout << "To make new array or exit, enter 0 \n";
                cin >> answer2;
                system("CLS");

                switch (answer2)
                {
                case (3):
                {
                    int minInUnsorted, maxInUnsorted;
                    minInUnsorted = 0;
                    maxInUnsorted = 0;

                    auto startFindingUn = std::chrono::high_resolution_clock::now();
                    for (int i = 0; i < N; i++)
                    {
                        if (unsortArr[i] <= minInUnsorted)
                        {
                            minInUnsorted = unsortArr[i];
                        }
                        if (unsortArr[i] >= maxInUnsorted)
                        {
                            maxInUnsorted = unsortArr[i];
                        }
                    }
                    cout << "\nMinimum element of an unsorted array: " << minInUnsorted;
                    cout << "\nMaximum element of an unsorted array: " << maxInUnsorted;
                    auto endFindingUn = std::chrono::high_resolution_clock::now();
                    auto timeFindingUn = std::chrono::duration_cast<std::chrono::nanoseconds>(endFindingUn - startFindingUn);
                    cout << "\nTime spent on unsorted finding (nanoseconds): " << std::fixed << timeFindingUn.count() << endl;

                    auto startFindingSo = std::chrono::high_resolution_clock::now();
                    cout << "\nMinimum element of the sorted array: " << arr[0];
                    cout << "\nMaximum element of the sorted array: " << arr[99];
                    auto endFindingSo = std::chrono::high_resolution_clock::now();
                    auto timeFindingSo = std::chrono::duration_cast<std::chrono::nanoseconds>(endFindingSo - startFindingSo);
                    cout << "\nTime spent on sorted finding (nanoseconds): " << std::fixed << timeFindingSo.count() << endl;

                    break;
                }

                case (4):
                    int average;

                    average = round((arr[0] + arr[99]) / 2);
                    cout << "\nThe average value of the maximum and minimum values: " << average;
                    cout << "\nIndexes of all elements that are equal to this value: ";
                    int numberInArray;
                    numberInArray = 0;
                    for (int i = 0; i < 100; i++) {
                        if (unsortArr[i] == average) {
                            numberInArray += 1;
                            cout << "\n" << i << "\n";
                        }
                    }
                    cout << "Total of these in the array: " << numberInArray << "\n";

                    break;

                case (5):
                    cout << "To search for elements in the sorted array that are less than the number a, enter a: ";
                    int a;
                    int lowerThanA;
                    lowerThanA = 0;
                    cin >> a;
                    for (int i = 0; i < N; i++) {
                        if (arr[i] < a) {
                            lowerThanA += 1;
                        }
                    }
                    cout << "\nElements less than a: " << lowerThanA << endl;
                    break;

                case (6):
                    cout << "To search for elements in the sorted array that are greater than the number b, enter b: ";
                    int b;
                    int higherThanB;
                    higherThanB = 0;
                    cin >> b;
                    for (int i = 0; i < N; i++) {
                        if (arr[i] > b) {
                            higherThanB += 1;
                        }
                    }
                    cout << "\nElements greater than  b: " << higherThanB << endl;
                    break;

                case (7):
                {
                    int x;
                    bool answer7;
                    bool isExists = false;

                    cout << "\nUnsorted array: \n";
                    for (int i = 0; i < N; i++)
                        cout << unsortArr[i] << " ";

                    cout << "\n\nSorted array: \n";
                    for (int i = 0; i < N; i++)
                        cout << arr[i] << " ";

                    while (true) {
                        cout << "\nWhat integer do you want to find? \n";
                        cin >> x;

                        auto startSort = std::chrono::high_resolution_clock::now();
                        for (int i = 0; i < N; i++) {
                            if (arr[i] == x) {
                                isExists = true;
                                break;
                            }
                        }
                        auto endSort = std::chrono::high_resolution_clock::now();
                        auto timeSort = std::chrono::duration_cast<std::chrono::nanoseconds>(endSort - startSort);
                        cout << "\nTime spent on regular sorted finding (nanoseconds): " << std::fixed << timeSort.count() << endl;

                        auto startBinary = std::chrono::high_resolution_clock::now();
                        int result = binarySearch(arr, x, 0, N - 1);
                        auto endBinary = std::chrono::high_resolution_clock::now();
                        auto timeBinary = std::chrono::duration_cast<std::chrono::nanoseconds>(endBinary - startBinary);
                        cout << "\nTime spent on binary sorted finding (nanoseconds): " << std::fixed << timeBinary.count() << endl;

                        if (result == -1)
                            cout << "Not found" << "\n";
                        else
                            cout << "Element is found at index " << result << "\n";

                        cout << fixed << "\nDifference between Binary search and regular search (nanoseconds): " << timeSort.count() - timeBinary.count() << "\n";

                        cout << "\nExit? 1/0";
                        cin >> answer7;
                        if (answer7) {
                            system("CLS");
                            break;
                        }
                    }
                    break;
                }

                case (8):
                {
                    bool answer8;
                    cout << "\nUnsorted array: \n";
                    for (int i = 0; i < N; i++)
                        cout << unsortArr[i] << " ";

                    while (true) {
                        cout << "\nTo swap two array elements, enter their indexes: \n";
                        int first;
                        int second;
                        cout << "First: ";
                        cin >> first;
                        cout << "Second: ";
                        cin >> second;
                        cout << "\n";

                        auto startSwap = std::chrono::high_resolution_clock::now();
                        swap(unsortArr[first], unsortArr[second]);
                        auto endSwap = std::chrono::high_resolution_clock::now();
                        auto timeSwap = std::chrono::duration_cast<std::chrono::nanoseconds>(endSwap - startSwap);
                        cout << "\nTime spent on swaping(nanoseconds): " << std::fixed << timeSwap.count() << endl;

                        cout << "\nUnsorted array: \n";
                        for (int i = 0; i < N; i++)
                            cout << unsortArr[i] << " ";

                        cout << "\nExit? 1/0";
                        cin >> answer8;
                        if (answer8) {
                            system("CLS");
                            break;
                        }
                    }
                    break;
                }

                case (0):
                    break;

                default:
                    cout << "Oh, no! This task doesn't exist. Let's try again.\n";
                    break;
                }
            }
            break;
        }
        case (0):
            cout << "Have a nice day!\n";
            break;

        default:
            cout << "Oh, no! This task doesn't exist. Let's try again.\n";
            break;
        }
    }
}

void animation(int* p, int s) {
    system("CLS");
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << *(p + s * i + j) << " ";
        }
        cout << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(40));
}

void withoutAnimation(int* p, int s) {
    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            cout << *(p + s * i + j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void fillSnake(int* p, int s) {

    int counter = 1;

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            *(p + s * j + i) = 0;
        }
    }
    for (int i = 0; i < s; i++) {
        if ((i % 2) != 0) {
            for (int j = (s - 1); j >= 0; j--) {
                *(p + s * j + i) = rand() % (s * s) + 1;
                //*(p + s * j + i) = counter; для проверки корректной работы
                animation(p, s);
                counter++;
            }
        }
        else {
            for (int j = 0; j < s; j++) {
                *(p + s * j + i) = rand() % (s * s) + 1;
                //*(p + s * j + i) = counter; для проверки корректной работы
                animation(p, s);
                counter++;
            }
        }
    }
}

void fillSpiral(int* p, int s) {

    for (int i = 0; i < s; ++i) {
        for (int j = 0; j < s; ++j) {
            *(p + s * j + i) = 0;
        }
    }
    int c = 1, j, k = 0, d = 1;

    while (c < (s * s + 1))
    {
        k++;
        for (j = k - 1; j < s - k + 1; j++)
        {
            *(p + (k - 1) * s + j) = rand() % (s * s) + 1;
            //*(p + (k - 1) * s + j) = c;
            animation(p, s);
            c++;
        }   //верх

        for (j = k; j < s - k + 1; j++)
        {
            *(p + j * s + (s - k)) = rand() % (s * s) + 1;
            //*(p + j * s + (s-k)) = c;
            animation(p, s);
            c++;
        }   //право

        for (j = s - k - 1; j >= k - 1; j--)
        {
            *(p + (s - k) * s + j) = rand() % (s * s) + 1;
            //*(p + (s - k) * s + j) = c;
            animation(p, s);
            c++;
        }   //низ

        for (j = s - k - 1; j >= k; j--)
        {
            *(p + j * s + (k - 1)) = rand() % (s * s) + 1;
            //*(p + j * s + (k-1)) = c;
            animation(p, s);
            c++;
        }   //лево
    }
}

void maths(int* p, int s) {

    int answer3 = 0;
    int n;

    while (answer3 != 5) {

        cout << "\n What exectly do you want?\n";
        cout << "\nTo reduce, enter 1\n";
        cout << "\nTo increase, enter 2\n";
        cout << "\nTo multiplie, enter 3\n";
        cout << "\nTo divide, enter 4\n";
        cout << "\nTo exit, enter 5 \n";
        cin >> answer3;

        switch (answer3) {

        case 1:
            cout << "And enter a number:";
            cin >> n;

            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < s; ++i) {
                for (int j = 0; j < s; ++j) {
                    *(p + s * j + i) = *(p + s * j + i) - n;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 2:
            cout << "And enter a number:";
            cin >> n;

            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < s; ++i) {
                for (int j = 0; j < s; ++j) {
                    *(p + s * j + i) = *(p + s * j + i) + n;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 3:
            cout << "And enter a number:";
            cin >> n;

            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < s; ++i) {
                for (int j = 0; j < s; ++j) {
                    *(p + s * j + i) = *(p + s * j + i) * n;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 4:
            cout << "And enter a number:";
            cin >> n;

            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < s; ++i) {
                for (int j = 0; j < s; ++j) {
                    *(p + s * j + i) = *(p + s * j + i) / n;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 5:
            break;

        default:
            cout << "Oh, no! This task doesn't exist. Let's try again.\n";
            break;
        }
    }
    system("CLS");
}

void bubbleSort(int* p, int s) {

    bool sw = 1;

    while (sw != 0) {
        sw = 0;
        for (int i = 0; i < (s * s - 1); i++) {
            if ((*(p + i)) > (*(p + i + 1))) {
                swap((*(p + i)), (*(p + i + 1)));
                sw = 1;
            }
        }
    }
}

void blocks(int* p, int s) {

    int answer1 = 0;
    int half = s / 2;
    int t;

    while (answer1 != 5) {

        cout << "\n What exectly do you want?\n";
        cout << "\na)To rearrange with a snake, enter 1\n";
        cout << "\nb)To rearrange the diagonal, enter 2\n";
        cout << "\nc)To rearrange the vertical, enter 3\n";
        cout << "\nd)To rearrange the horizontal, enter 4\n";
        cout << "\nTo exit, enter 5 \n";
        cin >> answer1;

        switch (answer1) {

        case 1:
            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < half; ++i) {
                for (int j = 0; j < half; ++j) {
                    t = *(p + s * j + i);
                    *(p + s * j + i) = *(p + s * (j + half) + i);
                    *(p + s * (j + half) + i) = *(p + s * (j + half) + (i + half));
                    *(p + s * (j + half) + (i + half)) = *(p + s * j + (i + half));
                    *(p + s * j + (i + half)) = t;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 2:
            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < half; ++i) {
                for (int j = 0; j < half; ++j) {
                    t = *(p + s * j + i);
                    *(p + s * j + i) = *(p + s * (j + half) + (i + half));
                    *(p + s * (j + half) + (i + half)) = t;
                }
            }
            for (int i = 0; i < half; ++i) {
                for (int j = 0; j < half; ++j) {
                    t = *(p + s * (j + half) + i);
                    *(p + s * (j + half) + i) = *(p + s * j + (i + half));
                    *(p + s * j + (i + half)) = t;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 3:
            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < s; ++i) {
                for (int j = 0; j < half; ++j) {
                    t = *(p + s * j + i);
                    *(p + s * j + i) = *(p + s * (j + half) + i);
                    *(p + s * (j + half) + i) = t;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 4:
            cout << "\nBefore:\n";
            withoutAnimation(p, s);
            for (int i = 0; i < half; ++i) {
                for (int j = 0; j < s; ++j) {
                    t = *(p + s * j + i);
                    *(p + s * j + i) = *(p + s * j + (i + half));
                    *(p + s * j + (i + half)) = t;
                }
            }
            cout << "\nAfter:\n";
            withoutAnimation(p, s);
            break;

        case 5:
            break;

        default:
            cout << "Oh, no! This task doesn't exist. Let's try again.\n";
            break;
        }
    }
    system("CLS");
}

void PW3()
{
    srand(time(0));

    const int size = 6;
    int A[size][size];
    int* p = &A[0][0];

    int end = size * size - 1;
    int begin = 0;

    cout << "\nLet's make some matrix (6*6)\n";
    int answer;
    answer = 3;

    while (answer != 0) {
        cout << "\nTo make new matrix with Snake animation, enter 1\n";
        cout << "\nTo make new matrix with Spiral animation, enter 2\n";
        cout << "\nTo exit, enter 0 \n";
        cin >> answer;
        system("CLS");

        if (answer == 1 || answer == 2) {
            if (answer == 1)
                fillSnake(p, size);

            if (answer == 2)
                fillSpiral(p, size);

            while (answer != 4) {
                cout << "\nTo make new matrix, rearranging its blocks in accordance with the schemes(a, b, c, d), enter 1\n";
                cout << "\nTo sort elements by bubble sort, using pointer arithmetic, enter 2\n";
                cout << "\nTo reduce, increase, multiplie, or divide all matrix elements by the number entered by the user, enter 3\n";
                cout << "\nTo make new matrix, enter 4 \n";
                cin >> answer;
                system("CLS");

                if (answer == 1 || answer == 2 || answer == 3) {
                    if (answer == 1)
                        blocks(p, size);

                    if (answer == 2) {
                        cout << "\nUnsorted array:\n";
                        withoutAnimation(p, size);
                        bubbleSort(p, size);
                        cout << "\nSorted array:\n";
                        withoutAnimation(p, size);
                    }

                    if (answer == 3)
                        maths(p, size);
                }

                else if (answer == 4) {
                    cout << "Let's make some matrix (6*6)\n";
                }

                else {
                    cout << "Oh, no! This task doesn't exist. Let's try again.\n";
                }
            }
        }

        else if (answer == 0) {
            cout << "Have a nice day!\n";
        }

        else {
            cout << "Oh, no! This task doesn't exist. Let's try again.\n";
        }
    }
}

string note() {
    int answer2;
    string text0, text;
    cout << "\nSelect the input method\n";
    cout << "\n1) Keyboard\n";
    cout << "\n2) File (D:\\hello.txt)\n";
    cin >> answer2;

    if (answer2 == 1) {
        cin.ignore();
        getline(cin, text0);
        text = text0;
    }
    else if (answer2 == 2) {
        ifstream in("D:\\hello.txt"); // окрываем файл для чтения
        if (in.is_open())
        {
            while (getline(in, text))
            {
                cout << "You entered: " << endl;
                cout << text << endl;
            }
        }
        else cout << "File doesn't exist\n";
        in.close();
    }
    return text;
}

string cleaning(string text, int len) {

    while (text[0] == '.' || text[0] == ' ') {
        text.erase(0, 1);
        len--;
    }
    while (text[len] == ' ') {
        text.erase(len, 1);
        len--;
    }
    for (int i = 0; i < len; i++) {
        if (text[i] == ' ' && (text[i + 1] == ' ' || text[i + 1] == ',' || text[i + 1] == '.' || text[0] == ' ')) {
            text.erase(i, 1);
            len--;
        }
    }
    for (int i = 0; i < len; i++) {
        if ((text[i] == '.' && text[i + 1] == '.') && text[i + 2] == '.')
            i += 3;
        else if ((text[i] == '.' || text[i] == ',' || text[i] == ';' || text[i] == ':' || text[i] == '!' || text[i] == '?') && (text[i + 1] == '.' || text[i + 1] == ',' || text[i + 1] == ';' || text[i + 1] == ':' || text[i + 1] == '!' || text[i + 1] == '?')) {
            text.erase(i, 1);
            len--;
            i--;
        }
    }
    for (int i = 0; i < len; i++) {
        if (i == 0)
            text[i] = toupper(text[i]);
        else
            text[i] = tolower(text[i]);
    }
    for (int i = 0; i < len; i++) {
        if (text[i] == '.' && text[i + 1] == ' ')
            text[i + 2] = toupper(text[i + 2]);
    }
    return text;
}

void exerciseThree(string text) {
    int End = 0;
    string str, word;
    char letters[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    char numbers[10] = { '0','1','2','3','4','5','6','7','8','9' };

    int len = text.length();
    for (int i = 0; i < len; i++) {
        if ((text[i] == ';' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?')) {
            text.erase(i, 1);
            len--;
            i--;
        }
    }
    str = text;
    cout << "\nAll words containing only letters - ";

    while (End >= 0) {
        bool foundNum = false;
        End = str.find(' ');
        word = str.substr(0, End);
        str = str.erase(0, End + 1);
        for (int i = 0; i < word.length(); i++) {
            for (auto j : numbers)
                if (word[i] == j) {
                    foundNum = true;
                    break;
                }
        }
        if (!foundNum) {
            cout << word << " ";
        }
    }
    End = 0;
    str = text;
    cout << "\n\nAll words containing only numbers - ";
    while (End >= 0) {
        bool foundNum = false;
        End = str.find(' ');
        word = str.substr(0, End);
        str = str.erase(0, End + 1);
        for (int i = 0; i < word.length(); i++) {
            for (auto j : letters) {
                if (word[i] == j) {
                    foundNum = true;
                    break;
                }
            }
        }
        if (!foundNum) cout << word << " ";
    }
    End = 0;
    str = text;
    cout << "\n\nAll words containing only numbers and letters - ";
    while (End >= 0) {
        bool foundNum = false;
        End = str.find(' ');
        word = str.substr(0, End);
        str = str.erase(0, End + 1);
        for (int i = 0; i < word.length(); i++) {
            for (auto j : letters) {
                if (word[i] == j) {
                    for (int m = i; m < word.length(); m++) {
                        for (auto k : numbers) {
                            if (word[m] == k) {
                                foundNum = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < word.length(); i++) {
            for (auto j : numbers) {
                if (word[i] == j) {
                    for (int m = i; m < word.length(); m++) {
                        for (auto k : letters) {
                            if (word[m] == k) {
                                foundNum = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
        if (foundNum) cout << word << " ";
    }
}

void exerciseFour(string text) {
    int len = text.length();
    for (int i = 0; i < len; i++) {
        if ((text[i] == ';' || text[i] == ',' || text[i] == '.' || text[i] == ':' || text[i] == '!' || text[i] == '?')) {
            text.erase(i, 1);
            len--;
            i--;
        }
    }
    string word, text2, line;
    text2 = "";
    text += " ";
    int index = 0;
    //cout << text << endl;
    int End = 0;

    while (End >= 0) {
        End = text.find(' ');
        word = text.substr(0, End);
        text = text.erase(0, End + 1);
        if (word.length() < 10) {
            int k = 10 - word.length();
            for (int j = 0; j < k; j++) {
                word += " ";
            }
        }
        text2 += word;
    }
    text2 = text2.erase(text2.length() - 10, text2.length() - 1);

    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < text2.length(); i += 10) {
            line += text2[i + j];
            line += " ";
        }
        cout << line << endl;
        line = "";
    }
}

void exerciseFive(string text) {
    string subText0, subText;
    bool foundOne = false;
    bool found = true;
    int answer = 1;
    while (answer == 1) {

        cout << "\nEnter substring:" << endl;
        cin.ignore();
        getline(cin, subText0);

        subText = subText0;

        for (int i = 0; i < text.length(); i++) {
            if (text[i] == subText[0]) {
                for (int j = 1; j < subText.length(); j++) {
                    if (text[i + j] != subText[j])
                        found = false;
                }
                if (found == true) {
                    cout << "First index of substring - " << i << "\n";
                    foundOne = true;
                }
            }
            found = true;
        }
        if (!foundOne)
            cout << "This substring doesn't exist";
        cout << "\n\nDo you wanna repeat? (yes - 1; no - 0) (please repeat entering if it isn't true)" << endl;
        cin >> answer;
    }
}

void PW4()
{
    int answer1, len;
    answer1 = 1;
    len = 0;
    string text;

    text = note(); // используется функция записи введенного текста (1 задание)

    while (text[len])
        ++len;
    cout << "\nNumber of symbols in the text: " << len << endl;

    text = cleaning(text, len); // 2 задание
    cout << "\nEdited input text:" << endl;
    cout << text << endl;

    exerciseThree(text);

    cout << "\n\nDisplays all words in the original sequence vertically on the screen:\n" << endl;
    exerciseFour(text);

    exerciseFive(text);
}

int main()
{
    int practicalWork = 1;
	while (practicalWork != 0) {
		system("CLS");
        cout << "To choose Practical work, Enter the number of practical work or enter 0 for exit: \n";
        cout << "\t1) Data types and their internal representation in memory \n";
        cout << "\t2) One-dimensional static arrays \n";
        cout << "\t3) Pointers \n";
        cout << "\t4) String \n\n";
		cin >> practicalWork;
		switch (practicalWork) {
		case 1:
			system("CLS");
			PW1();
			break;
		case 2:
			system("CLS");
			PW2();
			break;
		case 3:
			system("CLS");
			PW3();
			break;
		case 4:
			system("CLS");
			PW4();
			break;
		case 0:
			cout << "Have a nice day!\n";
			break;
		default:
			cout << "Oh, no! This task doesn't exist. Let's try again.\n";
			break;
		}
	}
	return 0;
}