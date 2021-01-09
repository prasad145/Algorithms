import java.util.Scanner;
public class InsertionSort {
    
    void sort_insertion(int arr[])
    {
        for(int i = 1; i < arr.length; i++)
        {
            int key = arr[i];
            int j = i - 1;
            while(j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
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
      InsertionSort obj = new InsertionSort();
      int arr[] = { 12, 11, 13, 5, 6 };
      obj.sort_insertion(arr);
      print_array(arr);
    }
}















