package com.demo.test;

import java.util.Arrays;

import com.demo.sort.BubbleSort;

public class TestBubbleSort {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] arr= {5,7,8,9,3,4,5,2};
		
//		int[] srtArr=BubbleSort.bubbleSort(arr);
//		System.out.println(Arrays.toString(srtArr));
		
		int [] impbarr= BubbleSort.improvedBubbleSort(arr);
	  System.out.println(Arrays.toString(impbarr));
	}

}
