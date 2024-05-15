#include <iostream>
#include <vector>
#include <algorithm>

// define a struct to represent vector
struct Vector {
    std::vector<int> elements;
    double comparisonValue;

    Vector(const std::vector<int>& elements)
        : elements(elements), comparisonValue(0.0)
    {
        calculateComparisonValue();
    }

    // Function to calculate comparison value
    void calculateComparisonValue()
    {
        comparisonValue = elements.size();
        for (const int& element : elements)
        {
            comparisonValue += (element > 0) ? (element * element) : -(element * element);
        }
    }

    // Overloading the less than operator for sorting
    friend bool operator < (const Vector& a, const Vector& b)
    {
        return a.comparisonValue < b.comparisonValue;
    }
};

int main()
{
    int N;
    std::cin >> N;

    std::vector<Vector> vectors;
    for (int i = 0; i < N; ++i)
    {
        int M;
        std::cin >> M;

        std::vector<int> elements(M);
        for (int j = 0; j < M; ++j)
        {
            std::cin >> elements[j];
        }

        vectors.push_back(Vector(elements));
    }

    // sort the vectors in reverse order (descending)
    std::sort(vectors.rbegin(), vectors.rend());

    for (const Vector& vector : vectors)
    {
        for (const int& element : vector.elements)
        {
            std::cout << element << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}