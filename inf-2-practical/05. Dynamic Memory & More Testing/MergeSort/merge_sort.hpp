#include <iostream>

#pragma once

int *copy(int *input_begin, int *input_end, int *output_begin)
{
    while (input_begin != input_end)
    {
        *(output_begin++) = *(input_begin++);
    }
    return output_begin;
}

int *merge(int *input1_begin, int *input1_end, int *input2_begin, int *input2_end, int *output_begin)
{
    while (input1_begin != input1_end && input2_begin != input2_end)
    {
        if (*input1_begin < *input2_begin)
        {
            *(output_begin++) = *(input1_begin++);
        }
        else
        {
            *(output_begin++) = *(input2_begin++);
        }
    }
    output_begin = copy(input1_begin, input1_end, output_begin);
    return copy(input2_begin, input2_end, output_begin);
}

void inplace_merge(int *arr_begin, int *arr_middle, int *arr_end)
{
    int *buffer{new int[arr_end - arr_begin]};
    int *buffer_end = merge(arr_begin, arr_middle, arr_middle, arr_end, buffer);
    copy(buffer, buffer_end, arr_begin);
    delete[] buffer;
}

void merge_sort(int *arr_begin, int *arr_end)
{
    if (arr_begin >= arr_end - 1)
    {
        return;
    }
    int *arr_middle = arr_begin + (arr_end - arr_begin) / 2;
    merge_sort(arr_begin, arr_middle);
    merge_sort(arr_middle, arr_end);
    inplace_merge(arr_begin, arr_middle, arr_end);
}