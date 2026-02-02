package com.demo.test;

import com.demo.sort.QuickSort;

public class TestQuickSort {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] arr= {5,3,8,1,4,6,2,7};
		QuickSort.quickSort(arr,0,arr.length-1);
	}

}
