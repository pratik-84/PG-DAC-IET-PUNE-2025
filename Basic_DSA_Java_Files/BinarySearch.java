
public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {5, 10, 15, 20, 25};
        int key = 20;

        int low = 0, high = arr.length - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(arr[mid] == key) {
                System.out.println("Element found at index: " + mid);
                break;
            }
            else if(arr[mid] < key) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }
}
