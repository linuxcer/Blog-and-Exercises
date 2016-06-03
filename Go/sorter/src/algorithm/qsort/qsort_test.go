package qsort

import "testing"

func TestQuictSort1(t *testing.T) {
    values := []int {5, 4, 3, 2, 1}
    QuickSort(values, 0, len(values) - 1)
    if values[0] != 1 || values[1] != 2 || values[2] != 3 || values[3] != 4 || values[4] != 5 {
        t.Error("QuickSort() failed. Got", values, "Expected 1 2 3 4 5")
    }
}

func TestQuictSort2(t *testing.T) {
    values := []int {5}
    QuickSort(values, 0, len(values) - 1)
    if values[0] != 5 {
        t.Error("QuickSort() failed. Got", values, "Expected 5")
    }
}
