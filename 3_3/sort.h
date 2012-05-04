#ifndef SORT_H
#define SORT_H
#pragma once

const int n = 5;

/**
  @class Sort
  ����������� ����� ���������� ������� (�������) �� �� ������ ���������
  */

class Sort
{
public:
    /**
      @brief ���������� ���������� ����� ����� ������� �� ������ ���������
      @param mas ����������� ������
      @param n ����� ������ (�������) ������������ �������
      */
    void sorting (int mas[n][n]);
private:
    /**
      @brief �����, �������� ������� ��� ������ �������, �.�. ��� �������
      @param a[] ������ �� �������������� �����
      @param b[] ������ �� �������������� �����
      */
    void swap (int a[], int b[]);
};

#endif // SORT_H
