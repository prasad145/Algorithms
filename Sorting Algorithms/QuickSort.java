import java.util.Scanner;
public class QuickSort {
    
    int partition(int a[], int l, int r)
    {
        int pivot = a[r];
        int pIndex = l;
        for(int i = l; i <= r - 1; i++)
        {
            if(a[i] <= pivot)
            {
                int tmp = a[pIndex];
                a[pIndex] = a[i];
                a[i] = tmp;
                pIndex += 1;
            }
        }
        int tmp = a[pIndex];
        a[pIndex] = a[r];
        a[r] = tmp;
        
        return pIndex;
    }
    
    void quick_sort(int a[], int l, int r)
    {
        if(l < r)
        {
           int pivot = partition(a, l, r);
           quick_sort(a, l, pivot - 1);
           quick_sort(a, pivot + 1, r);
        }
    }
 
    static void print_array(int arr[])
    {
        for(int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
        
        System.out.println("\n");
        
    }
    
    
    public static void main(String args[]) {
      QuickSort obj = new QuickSort();
      int arr[] = { 12, 11, 13, 5, 6, 7 };
      obj.quick_sort(arr, 0, arr.length - 1);
      print_array(arr);
    }
}















