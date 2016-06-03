package qsort

func QuickSort(values []int, left, right int) {
    if left >= right {
        return
    }
    temp := values[left]
    i, j := left, right
    for i < j {
        for values[j] >= temp && i < j {
            j--
        }
        values[i] = values[j]
        for values[i] <= temp && i < j {
            i++
        }
        values[j] = values[i]
        println(i, j)
    }
    values[i] = temp
    QuickSort(values, left, i - 1)
    QuickSort(values, i + 1, right)
}
