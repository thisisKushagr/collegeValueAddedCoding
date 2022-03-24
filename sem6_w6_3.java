import java.io.*;
import java.util.*;

public class Solution {

    static void findSubarray(int arr[], int m) {
        int wL = 0, wR = 0;
        int bestL = 0, bestWindow = 0;
        int zeroCount = 0;
        while (wR < arr.length) {
            if (zeroCount <= m) {
                if (arr[wR] == 0)
                    zeroCount++;
                wR++;
            }
            if (zeroCount > m) {
                if (arr[wL] == 0)
                    zeroCount--;
                wL++;
            }
            if ((wR-wL > bestWindow) && (zeroCount<=m)) {
                bestWindow = wR-wL;
                bestL = wL;
            }
        }
        for (int i=0; i<bestWindow; i++) {
            if (arr[bestL+i] == 0)
                arr[bestL+i]++;
        }
        //Printing output
        System.out.println(bestWindow);
        for (int i=0; i<arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }
    
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int arr[] = new int[n];
        for(int i=0; i<n; i++){
            arr[i] = sc.nextInt();
        }
        findSubarray(arr, k);
    }
}
