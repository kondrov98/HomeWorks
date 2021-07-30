#include <iostream>
#include <vector>
#include <cassert> // ��� assert()



class ArrayInt
{
private:
    int m_length;
    int* m_data;

public:
    ArrayInt() : m_length(0), m_data(nullptr)
    { }

    ArrayInt(int length) :
        m_length(length)
    {
        assert(length >= 0);

        if (length > 0)
            m_data = new int[length];
        else
            m_data = nullptr;
    }

    ~ArrayInt()
    {
        delete[] m_data;
    }

    void erase()
    {
        delete[] m_data;

        // ����� ��� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
        m_data = nullptr;
        m_length = 0;
    }
    int getLength() { return m_length; }

    int& operator[](int index)
    {
        assert(index >= 0 && index < m_length);
        return m_data[index];
    }

    // ������� resize �������� ������ �������. ��� ������������ �������� �����������. ������� ���������
    void resize(int newLength)
    {
        // ���� ������ ��� ������ ����� � return
        if (newLength == m_length)
            return;

        // ���� ����� ������� ������ ������ � ������ ��� � ����� return
        if (newLength <= 0)
        {
            erase();
            return;
        }

        // ������ �����, ��� newLength >0
        // �������� ����� ������
        int* data = new int[newLength];

        // ����� ����� ����������� � ����������� ���������� ��������� � ����� ������
        // ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
        if (m_length > 0)
        {
            int elementsToCopy = (newLength > m_length) ? m_length : newLength;

            // ���������� �������� ��������
            for (int index = 0; index < elementsToCopy; ++index)
                data[index] = m_data[index];
        }

        // ������� ������ ������, ��� ��� �� ��� ��� �� �����
        delete[] m_data;

        // � ���������� ������ ������� ������� �����! �������� ��������, m_data ���������
        // �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������. ���������
        // ������ ���� ����������� ���������� � ��� �� ����� ����������, ����� ������ �� ������� ���������
        m_data = data;
        m_length = newLength;
    }

    void insertBefore(int value, int index)
    {
        // �������� ������������ ������������� �������
        assert(index >= 0 && index <= m_length);

        // ������� ����� ������ �� ���� ������� ������ ������� �������
        int* data = new int[m_length + 1];

        // �������� ��� �������� �� index-�
        for (int before = 0; before < index; before++)
            data[before] = m_data[before];

        // ��������� ����� ������� � ����� ������
        data[index] = value;

        // �������� ��� �������� ����� ������������ ��������
        for (int after = index; after < m_length; ++after)
            data[after + 1] = m_data[after];

        // ������� ������ ������ � ���������� ������ ���� ����� 
        delete[] m_data;
        m_data = data;
        ++m_length;
    }



    //--------------------------------------------------------------------------------------------------------Task1
    void pop_back()
    {

        // ������� ����� ������ �� ���� ������� ������ ������� �������
        int* data = new int[m_length - 1];

        // �������� ��� �������� �� ����������
        for (int before = 0; before < m_length - 1; before++)
            data[before] = m_data[before];

        // ������� ������ ������ � ���������� ������ ���� ����� 
        delete[] m_data;
        m_data = data;
        delete[] data;
        --m_length;
        data = nullptr;
    }


    void pop_front()
    {

        // ������� ����� ������ �� ���� ������� ������ ������� �������
        int* data = new int[m_length - 1];

        // �������� ��� �������� �� ����� �������
        for (int before = 0; before < m_length - 1; ++before)
            data[before] = m_data[before];

        // ������� ������ ������ � ���������� ������ ���� ����� 
        delete[] m_data;
        m_data = data;
        delete[] data;
        --m_length;
        data = nullptr;
    }

    void sort()
    {
        int pos, temp;
        for (int i = 1; i < m_length; i++)
        {
            temp = m_data[i];
            pos = i - 1;
            while (pos >= 0 && m_data[pos] > temp)
            {
                m_data[pos + 1] = m_data[pos];
                pos--;
            }
            m_data[pos + 1] = temp;
        }
    }

    void printData()
    {
        std::cout << "[ ";
        for (int i = 0; i < m_length; i++)
        {
            std::cout << m_data << ", ";
        }
        std::cout << " ]";
    }
    //--------------------------------------------------------------------------------------------------------Task1
};
//--------------------------------------------------------------------------------------------------------Task2
int Algoritm(std::vector<int>& array)
{
    int elem=0;
    std::vector<int> array2;
    for (int j = 0; j < array.size(); j++)
    {
        for (int i = 1; i < array.size(); i++)
        {
            if (array[j] == array[i])
            {
                for (int k = 0; k < array2.size(); k++)
                {
                    array2.push_back(array[j]);
                }
            }
            else
            {
                elem++;
            }
        }
    }
    return elem;
}
//--------------------------------------------------------------------------------------------------------Task2
