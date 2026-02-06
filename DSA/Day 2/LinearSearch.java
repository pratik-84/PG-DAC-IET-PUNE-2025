
public class LinearSearch {
    public static void main(String[] args) {
        int[] arr = {5,10,15,20};
        int key = 15;
        for(int i=0;i<arr.length;i++){
            if(arr[i] == key){
                System.out.println("Found at index " + i);
                return;
            }
        }
        System.out.println("Not found");
    }
}
