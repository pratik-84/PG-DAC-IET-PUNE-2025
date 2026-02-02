package com.demo.sort;

import java.util.Arrays;

public class BubbleSort {

	public static int[] bubbleSort(int[] arr) {
		// TODO Auto-generated method stub
		for(int i=0;i<arr.length;i++) {
			for(int j=1;j<arr.length-i;j++) {
				if(arr[j-1]>arr[j]) {
					int temp=arr[j-1];
					arr[j-1]=arr[j];
					arr[j]=temp;
				}
			}
			
//			System.out.println(Arrays.toString(arr));
		}
		return arr;
		
		
	}

	public static int[] improvedBubbleSort(int[] arr) {
		for(int i=0;i<arr.length;i++) {
			boolean flag= false;
			for(int j=1;j<arr.length-i;j++) {
				 flag=true;
				if(arr[j-1]>arr[j]) {
					int temp = arr[j-1];
					arr[j-1]=arr[j];
					arr[j] = temp;
				}
			}
			if(!flag) {
				break;
			}
		}
	
		return arr;
	}

	
	
}
