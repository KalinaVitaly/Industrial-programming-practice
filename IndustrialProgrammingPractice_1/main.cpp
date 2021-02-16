#include <iostream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>

void setMatrixSize(size_t &, size_t &);
void matrixMemoryAllocate(unsigned int **&, size_t, size_t);
void fillingMatrixManually(unsigned int **, size_t, size_t);
void fillingMatrixAutomatically(unsigned int **, size_t, size_t);
void fillingMatrixNulls(unsigned int **, size_t, size_t);
void outputMatrix(unsigned int **, size_t, size_t);
void copyMatrix(unsigned int **, unsigned int **, size_t, size_t);
void copyPartsOfMatrix(unsigned int **, unsigned int **, unsigned int **, unsigned int **, unsigned int **, size_t);
int chooseMatrixFillingMethod();
void clearMemory(unsigned int **&, size_t);

int main()
{
    srand(time(NULL));

    size_t firstMatrixHeight  {0};
    size_t firstMatrixWidth   {0};
    size_t secondMatrixHeight {0};
    size_t secondMatrixWidth  {0};
    size_t expandedMatrixSize {2};
    size_t x                  {0};
    size_t matrixHeight       {100};
    size_t matrixWidth        {100};

    unsigned int **firstMatrix         {nullptr};
    unsigned int **secondMatrix        {nullptr};
    unsigned int **thirdMatrix         {nullptr};
    unsigned int **fourthMatrix        {nullptr};
    unsigned int **partOfMatrix1       {nullptr};
    unsigned int **partOfMatrix2       {nullptr};
    unsigned int **partOfMatrix3       {nullptr};
    unsigned int **partOfMatrix4       {nullptr};
    unsigned int **partOfMatrix5       {nullptr};
    unsigned int **partOfMatrix6       {nullptr};
    unsigned int **partOfMatrix7       {nullptr};
    unsigned int **partOfMatrix8       {nullptr};
    unsigned int **intermediateMatrix1 {nullptr};
    unsigned int **intermediateMatrix2 {nullptr};
    unsigned int **intermediateMatrix3 {nullptr};
    unsigned int **intermediateMatrix4 {nullptr};
    unsigned int **intermediateMatrix5 {nullptr};
    unsigned int **intermediateMatrix6 {nullptr};
    unsigned int **intermediateMatrix7 {nullptr};
    unsigned int **auxiliaryMatrix1    {nullptr};
    unsigned int **auxiliaryMatrix2    {nullptr};
    unsigned int **auxiliaryMatrix3    {nullptr};
    unsigned int **auxiliaryMatrix4    {nullptr};
    unsigned int **resultMatrix        {nullptr};
    unsigned int **resultMatrix2       {nullptr};

    std::cout << "Вас приветствует программа" << std::endl
              << "быстрого перемножения матриц методом Штрассена" << std::endl << std::endl;

    /*
     * Ввод размеров матрицы пользователем
    */
    setMatrixSize(firstMatrixHeight, firstMatrixWidth);
    setMatrixSize(secondMatrixHeight, secondMatrixWidth);

    /*
     * Выделение памяти для матриц
    */
    matrixMemoryAllocate(firstMatrix, firstMatrixHeight, firstMatrixWidth);
    matrixMemoryAllocate(secondMatrix, secondMatrixHeight, secondMatrixWidth);

    /*
     * Выбор способа заполнения матриц
    */
    switch (chooseMatrixFillingMethod()) {
    case 1:
        /*
         * Вручную заполняем матрицу 1 и 2
        */ matrixMemoryAllocate(thirdMatrix, expandedMatrixSize, expandedMatrixSize);
        matrixMemoryAllocate(fourthMatrix, expandedMatrixSize, expandedMatrixSize);
        fillingMatrixManually(firstMatrix, firstMatrixHeight, firstMatrixWidth);
        fillingMatrixManually(secondMatrix, secondMatrixHeight, secondMatrixWidth);
        break;

    case 2:
        /*
         * Автоматически заполняем матрицу 1 и 2
        */
        fillingMatrixAutomatically(firstMatrix, firstMatrixHeight, firstMatrixWidth);
        fillingMatrixAutomatically(secondMatrix, secondMatrixHeight, secondMatrixWidth);
        break;
    }

    /*
     * Вывод матрицы
    */
    outputMatrix(firstMatrix, firstMatrixHeight, firstMatrixWidth);
    outputMatrix(secondMatrix, secondMatrixHeight, secondMatrixWidth);

    /*
     * Приведение матриц к требуемому размеру
    */
    std::cout << (expandedMatrixSize < firstMatrixWidth) << " " << (expandedMatrixSize < firstMatrixHeight)
              << " " << (expandedMatrixSize < secondMatrixWidth) << " " << (expandedMatrixSize < secondMatrixHeight) << std::endl;
    while (expandedMatrixSize < firstMatrixWidth || expandedMatrixSize < firstMatrixHeight
           || expandedMatrixSize < secondMatrixWidth || expandedMatrixSize < secondMatrixHeight)
    { expandedMatrixSize = expandedMatrixSize << 1; }

    matrixMemoryAllocate(thirdMatrix, expandedMatrixSize, expandedMatrixSize);
    matrixMemoryAllocate(fourthMatrix, expandedMatrixSize, expandedMatrixSize);

    /*
     * Заполняем нулями
    */
    fillingMatrixNulls(thirdMatrix, expandedMatrixSize, expandedMatrixSize);
    fillingMatrixNulls(fourthMatrix, expandedMatrixSize, expandedMatrixSize);

    /*
     * Копируем матрицу
    */
    copyMatrix(thirdMatrix, firstMatrix, firstMatrixHeight, firstMatrixWidth);
    copyMatrix(fourthMatrix, secondMatrix, secondMatrixHeight, secondMatrixWidth);

    std::cout << "Приведенные матрицы" << std::endl;
    std::cout << std::endl << "Матрица 1" << std::endl << std::endl;
    outputMatrix(thirdMatrix, expandedMatrixSize, expandedMatrixSize);
    std::cout << std::endl << "Матрица 2" << std::endl << std::endl;
    outputMatrix(fourthMatrix, expandedMatrixSize, expandedMatrixSize);

    /*
     * Разбиение матриц на подматрицы и их заполнение
    */
    size_t halfOfExpandedMatrixSize {expandedMatrixSize / 2};
    matrixMemoryAllocate(partOfMatrix1, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix2, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix3, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix4, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix5, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix6, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix7, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(partOfMatrix8, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);

    copyPartsOfMatrix(thirdMatrix, partOfMatrix1, partOfMatrix2, partOfMatrix3, partOfMatrix4, expandedMatrixSize / 2);
    copyPartsOfMatrix(fourthMatrix, partOfMatrix5, partOfMatrix6, partOfMatrix7, partOfMatrix8, expandedMatrixSize / 2);

    /*
     * Создание промежуточных матриц
    */
    matrixMemoryAllocate(intermediateMatrix1, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(intermediateMatrix2, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(intermediateMatrix3, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(intermediateMatrix4, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(intermediateMatrix5, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(intermediateMatrix6, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(intermediateMatrix7, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);

    /*
     * Вычисление значений промежуточных матриц
    */
    fillingMatrixNulls(intermediateMatrix1, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    fillingMatrixNulls(intermediateMatrix2, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    fillingMatrixNulls(intermediateMatrix3, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    fillingMatrixNulls(intermediateMatrix4, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    fillingMatrixNulls(intermediateMatrix5, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    fillingMatrixNulls(intermediateMatrix6, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    fillingMatrixNulls(intermediateMatrix7, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);

    for (size_t i {0}; i < halfOfExpandedMatrixSize; ++i) {
        for (size_t j {0}; j < halfOfExpandedMatrixSize; ++j) {
            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix1[i][j] += (partOfMatrix1[i][z] + partOfMatrix4[i][z])
                        * (partOfMatrix5[z][j] + partOfMatrix8[z][j]);
            }

            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix2[i][j] += (partOfMatrix3[i][z] + partOfMatrix4[i][z])
                        * partOfMatrix5[z][j];
            }

            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix3[i][j] += partOfMatrix1[i][z]
                        * (partOfMatrix6[z][j] - partOfMatrix8[z][j]);
            }

            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix4[i][j] += partOfMatrix4[i][z]
                        * (partOfMatrix7[z][j] - partOfMatrix5[z][j]);
            }

            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix5[i][j] += (partOfMatrix1[i][z] + partOfMatrix2[i][z])
                        * partOfMatrix8[z][j];
            }

            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix6[i][j] += (partOfMatrix3[i][z] - partOfMatrix1[i][z])
                        * (partOfMatrix5[z][j] + partOfMatrix6[z][j]);
            }

            for (size_t z {0}; z < halfOfExpandedMatrixSize; ++z) {
                intermediateMatrix7[i][j] += (partOfMatrix2[i][z] - partOfMatrix4[i][z])
                        * (partOfMatrix7[z][j] + partOfMatrix8[z][j]);
            }
        }
    }

    /*
     * Создание вспомогательных матриц
    */
    matrixMemoryAllocate(auxiliaryMatrix1, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(auxiliaryMatrix2, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(auxiliaryMatrix3, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);
    matrixMemoryAllocate(auxiliaryMatrix4, halfOfExpandedMatrixSize, halfOfExpandedMatrixSize);

    /*
     * Подсчет значений вспомогательных матриц из промежуточных
    */
    for (size_t i {0}; i < halfOfExpandedMatrixSize; ++i) {
        for (size_t j {0}; j < halfOfExpandedMatrixSize; ++j) {
            auxiliaryMatrix1[i][j] = intermediateMatrix1[i][j] + intermediateMatrix4[i][j]
                    - intermediateMatrix5[i][j] + intermediateMatrix7[i][j];
            auxiliaryMatrix2[i][j] = intermediateMatrix3[i][j] + intermediateMatrix5[i][j];
            auxiliaryMatrix3[i][j] = intermediateMatrix2[i][j] + intermediateMatrix4[i][j];
            auxiliaryMatrix4[i][j] = intermediateMatrix1[i][j] - intermediateMatrix2[i][j]
                    + intermediateMatrix3[i][j] + intermediateMatrix6[i][j];
        }
    }

    /*
     * Создание результирующей матрицы
    */
    matrixMemoryAllocate(resultMatrix, expandedMatrixSize, expandedMatrixSize);

    /*
     * Занесение информации из вспомогательных матриц в результирующую
     */
    for (size_t i {0}; i < halfOfExpandedMatrixSize; ++i) {
        for (size_t j {0}; j < halfOfExpandedMatrixSize; ++j) {
            resultMatrix[i][j] = auxiliaryMatrix1[i][j];
            resultMatrix[i][halfOfExpandedMatrixSize + j] = auxiliaryMatrix2[i][j];
            resultMatrix[halfOfExpandedMatrixSize + i][j] = auxiliaryMatrix3[i][j];
            resultMatrix[halfOfExpandedMatrixSize + i][halfOfExpandedMatrixSize + j] = auxiliaryMatrix4[i][j];
        }
    }

    /*
     * Выравнивание границ результирующей матрицы
     */
    for (size_t i {0}; i < expandedMatrixSize; ++i) {
        x = 0;
        for (size_t j {0}; j < expandedMatrixSize; ++j) {
            if (resultMatrix[i][j] != 0) {
                ++x;
                matrixHeight = 100;
            }
        }

        if (x == 0 && i < matrixHeight)
            { matrixHeight = i; }
    }

    for (uint i {0}; i < expandedMatrixSize; ++i) {
        x = 0;
        for (uint j {0}; j < expandedMatrixSize; ++j) {
            if (resultMatrix[j][i] != 0) {
                ++x;
                matrixWidth = 100;
            }
        }

        if (x == 0 && i < matrixWidth)
            { matrixWidth = i; }
    }

    matrixMemoryAllocate(resultMatrix2, matrixHeight, matrixWidth);
    for (size_t i {0}; i < matrixHeight; ++i)
        { std::copy(resultMatrix[i], resultMatrix[i] + matrixWidth, resultMatrix2[i]); }

    /*
     * Вывод результирующей матрицы
    */
    std::cout << std::endl << "Результирующая матрица" << std::endl << std::endl;
    outputMatrix(resultMatrix2, matrixHeight, matrixWidth);

    /*
     * Очистка динамической памяти
     */
    clearMemory(firstMatrix, firstMatrixHeight);
    clearMemory(secondMatrix, secondMatrixHeight);
    clearMemory(thirdMatrix, expandedMatrixSize);
    clearMemory(fourthMatrix, expandedMatrixSize);
    clearMemory(partOfMatrix1, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix2, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix3, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix4, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix5, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix6, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix7, halfOfExpandedMatrixSize);
    clearMemory(partOfMatrix8, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix1, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix2, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix3, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix4, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix5, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix6, halfOfExpandedMatrixSize);
    clearMemory(intermediateMatrix7, halfOfExpandedMatrixSize);
    clearMemory(auxiliaryMatrix1, halfOfExpandedMatrixSize);
    clearMemory(auxiliaryMatrix2, halfOfExpandedMatrixSize);
    clearMemory(auxiliaryMatrix3, halfOfExpandedMatrixSize);
    clearMemory(auxiliaryMatrix4, halfOfExpandedMatrixSize);
    clearMemory(resultMatrix, expandedMatrixSize);
    clearMemory(resultMatrix2, matrixHeight);

    return 0;
}

void clearMemory(unsigned int **&matrix, size_t height) {
    for (size_t i {0}; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void copyPartsOfMatrix(unsigned int ** mainMatrix, unsigned int ** matrix1,
                       unsigned int ** matrix2, unsigned int ** matrix3,
                       unsigned int ** matrix4, size_t expandedMatrixSize) {
    for (size_t i {0}; i < expandedMatrixSize; ++i) {
        for (size_t j {0}; j < expandedMatrixSize; ++j) {
            matrix1[i][j] = mainMatrix[i][j];
            matrix2[i][j] = mainMatrix[i][expandedMatrixSize + j];
            matrix3[i][j] = mainMatrix[expandedMatrixSize + i][j];
            matrix4[i][j] = mainMatrix[expandedMatrixSize + i][expandedMatrixSize + j];
        }
    }
}

void copyMatrix(unsigned int **matrix1, unsigned int **matrix2, size_t matrixHeight, size_t matrixWidth) {
    for (size_t i {0}; i < matrixHeight; ++i) {
        std::copy(matrix2[i], matrix2[i] + matrixWidth, matrix1[i]);
    }
}

void fillingMatrixNulls(unsigned int ** matrix, size_t matrixHeight, size_t matrixWidth) {
    for(size_t i {0}; i < matrixHeight; ++i) {
        std::fill(matrix[i], matrix[i] + matrixWidth, 0);
    }
}

void setMatrixSize(size_t & matrixHeight, size_t & matrixWidth) {
    do {
    std::cout << "Введите размеры матрицы" << std::endl;
    std::cin >> matrixHeight >> matrixWidth;
    } while (matrixHeight <= 0 || matrixWidth <= 0);
}

void matrixMemoryAllocate(unsigned int **& matrix, size_t matrixHeight, size_t matrixWidth) {
    matrix = new unsigned int*[matrixHeight];
    for (size_t i {0}; i < matrixHeight; ++i) {
        matrix[i] = new unsigned int[matrixWidth];
    }
}

int chooseMatrixFillingMethod() {
    int  choose {5};
    do {
        std::cout << "Выберите способ заполнения матриц" << std::endl
                  << "1 - Вручную" << std::endl
                  << "2 - Случайным образом" << std::endl;
        std::cin >> choose;
    } while(choose < 1 || choose > 2);

    return choose;
}

void fillingMatrixManually(unsigned int ** matrix, size_t matrixHeight, size_t matrixWidth) {
    for(size_t i {0}; i < matrixHeight; ++i) {
        for(size_t j {0}; j < matrixWidth; ++j) {
            std::cin >> matrix[i][j];
        }
    }
}

void fillingMatrixAutomatically(unsigned int ** matrix, size_t matrixHeight, size_t matrixWidth) {
    for(size_t i {0}; i < matrixHeight; ++i) {
        for(size_t j {0}; j < matrixWidth; ++j) {
            matrix[i][j] = rand() % 10;
        }
    }
}

void outputMatrix(unsigned int **matrix, size_t matrixHeight, size_t matrixWidth) {
    for(size_t i {0}; i < matrixHeight; ++i) {
        for(size_t j {0}; j < matrixWidth; ++j) {
           std::cout << static_cast<int>(matrix[i][j]) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
