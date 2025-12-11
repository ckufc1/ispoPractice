#include <iostream>
#include <clocale>

/// <summary>
/// Вычисляет время в пути, деля расстояние на скорость.
/// </summary>
/// <param name="distance">Расстояние, которое нужно преодолеть (например, км).</param>
/// <param name="velocity">Скорость движения (например, км/ч).</param>
/// <returns>Время в пути (тип float).</returns>
/// <remarks>
/// Внимание: если скорость равна 0, результат будет равен бесконечности (inf).
/// </remarks>
float CalculateTravelTime(float distance, float velocity)
{
    if (velocity == 0) return 0; // +1 к η2

    return distance / velocity; // +1 к η1
}

int main() {
    setlocale(LC_ALL, "Russian");

    float d, v;

    std::cout << "Введите расстояние: ";
    std::cin >> d;

    std::cout << "Введите скорость: ";
    std::cin >> v;

    float time = CalculateTravelTime(d, v);

    std::cout << "Время в пути: " << time << std::endl;

    return 0; // +1 к η1
}