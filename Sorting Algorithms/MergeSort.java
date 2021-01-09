import java.util.Scanner;
public class MergeSort {
    
    
    
    void merge(int a[], int l, int m, int r)
    {
        int n1 = m - l + 1; //because left subarray also contains the mid element so +1
        int n2 = r - m;
        
        int left[] = new int[n1];
        int right[] = new int[n2];
        
        for(int  i = 0; i < n1; i++)
        {
            left[i] = a[l + i];
        }
        
        for(int i = 0; i < n2; i++)
        {
            right[i] = a[m + i + 1];
        }
        
        int k = l;
        int i = 0, j =0;
        while(i < n1 && j < n2)
        {
            if(left[i] <= right[j])
            {
                a[k] = left[i];
                i++;
            }
            else
            {
                a[k] = right[j];
                j++;
            }
            k++;
        }
        
        while(i < n1)
        {
            a[k] = left[i];
            i++;
            k++;
        }
        
        while(j < n2)
        {
            a[k] = right[j];
            j++;
            k++;
        }
        
    }
    
    void merge_sort(int a[], int l, int r)
    {
        if(l < r)
        {
            int mid = l + (r - l) / 2;
            merge_sort(a, l, mid);
            merge_sort(a, mid + 1, r);
            merge(a, l, mid, r);
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
      MergeSort obj = new MergeSort();
      int arr[] = { 12, 11, 13, 5, 6, 7 };
      obj.merge_sort(arr, 0, arr.length - 1);
      print_array(arr);
    }
}















