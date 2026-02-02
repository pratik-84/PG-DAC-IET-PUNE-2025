package com.demo.sort;

import java.util.Arrays;

public class QuickSort {

	private static int partation(int[] arr, int start, int end) {
		
//		
//		
//		int pivot = start;
//		int i= start;
//		int j=end;
//		
//		
//		while(i<j) {
//			while(i<end&&arr[i]<arr[pivot]) {
//				i++;
//			}
//			while(j>start&& arr[j]>arr[pivot]) {
//				j--;
//			}
//			if(i<j) {
//				int temp=arr[i];
//				arr[j]=arr[i];
//				arr[i]=temp;
//				
//			}
//		}
//		if(pivot!=j) {
//			int temp=arr[pivot];
//			arr[pivot]=arr[j];
//			arr[j]=temp;
//		}
//		System.out.println(Arrays.toString(arr));
//		return j;
		
		// TODO Auto-generated method stub
		
		int pivot=start;
		int i= start;
		int j= end;
		
		while(i<j) {
			while(i<end && arr[i]<=arr[pivot]) {
				i++;
			}
			while(j>start&& arr[j]>arr[pivot]) {
				j--;
			}
			if(i<j) {
				int temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
		if(pivot!=j) {
			int temp=arr[pivot];
			arr[pivot]=arr[j];
			arr[j]=temp;
		}
		System.out.println(Arrays.toString(arr));
		return j;
	}

	public static void quickSort(int[] arr, int start, int end) {
		// TODO Auto-generated method stub
		
		if(start<end) {
			int p=partation(arr,start,end);
			quickSort(arr,start,p-1);
			quickSort(arr,p+1,end);
			
		}
		
	}
	
	

}
