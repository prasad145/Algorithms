import java.util.Scanner;
public class BubbleSort {
    
    void sort_Bubble(int arr[])
    {
        int n = arr.length;
        boolean ok = false;
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = 0; j < n - i - 1; j++)
            {
                if(arr[j] > arr[j + 1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    ok = true;
                }
            }
            if(!ok)
                break;
        }
    }
    
    void print_array(int arr[])
    {
        for(int i = 0; i < arr.length; i++)
        {
            System.out.print(arr[i] + " ");
        }
        
        System.out.println("\n");
        
    }
    
    
    public static void main(String args[]) {
      BubbleSort obj = new BubbleSort();
      int arr[] = {64, 34, 25, 12, 22, 11, 90};
      obj.sort_Bubble(arr);
      obj.print_array(arr);
    }
}















