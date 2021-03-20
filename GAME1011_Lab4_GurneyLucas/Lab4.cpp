#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
void swap(T* a, T* b) //only compare with the first and last letter of the word.
{
    T t = *a;
    *a = *b;
    *b = t;
}

int quickSortSwitch(int arr[], int low, int high)
{
    int move = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= move)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = quickSortSwitch(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high); 
    }
}

void Reverse(string& word)
{
    int n = word.length();

    for (int i = 0; i < n / 2; i++)
    {
        swap(word[i], word[n - i - 1]);
    }
}

int const MAX_SIZE = 10;

int main()
{
    unsigned seed = time(0);
    srand(seed);
    string word;
    string wordOG; 
    int choice = 0;

    while (true)
    {
        int quick[MAX_SIZE];

        for (int i = 0; i < MAX_SIZE; i++)
        {
            quick[i] = (rand() % 99);
        }

        cout << "what do you want to do? \n1. have a random quicksort\n2. reverse a word\n3. check if your word is a palindrome\n4. exit\n";
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            QuickSort(quick, 0, MAX_SIZE - 1);
            cout << "Sorted array: " << endl;
            for (int i = 0; i < MAX_SIZE; i++)
            {
                cout << quick[i] << " ";
            }
            cout << endl;
        }

        if (choice == 2)
        {
            cout << "Type in a word: ";
            cin >> word;
            int n = word.length();
            Reverse(word);
            cout << word << endl;
        }

        if (choice == 3)
        {
            cout << "Type in a word: ";
            cin >> word;
            int n = word.length();
            wordOG = word;
            Reverse(word);
            cout << word << endl;

            if (word == wordOG)
            {
                cout << "these words are the same.\n" << endl;
            }
            else
            {
                cout << "these words aren't the same.\n" << endl;
            }
        }

        if (choice == 4)
        {
            break;
        }

    }
    return 0;
}