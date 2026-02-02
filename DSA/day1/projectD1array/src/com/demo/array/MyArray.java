package com.demo.array;

import java.util.Arrays;

public class MyArray {
	private int [] arr;
	private int count;
	//static array
	public MyArray() {
		arr=new int [10];
		count =0;
	}
	
	public MyArray(int[] arr, int count) {
		
		this.arr = arr;
		this.count = count;
	}
	//dymanic array
	public MyArray(int size) {
		arr=new int[size];
		count=0;
	}
	public int getCapacity() {
		return arr.length;
	}
	public int size() {
		return count;
	}
	//add element at the end of array
	public boolean add(int n) {
		if(arr.length>count) {
			arr[count]=n;
			count++;
			return true;
		}
		return false;
	}
	public boolean addAtIndex(int n,int pos) {
		if(arr.length>count&&pos<count) {
			for(int i=count;i>pos;i--) {
				arr[i]=arr[i-1];
			}
			arr[pos]=n;
			count++;
			return true;
		}return false;
	}
	
	public int searchValue(int n) {
		for(int i=0;i<count;i++){
			if(arr[i]==n) {
				return i;
			}
		}return -1;
	}
	public boolean deleteByPos(int pos) {
		if(count>pos) {
			for(int i=pos;i<count-1;i++) {
				arr[i]=arr[i+1];
			}
			arr[count-1]=0;
			count--;
			return true;
		}return false;
	}
	//delete by first occureance of number
	public boolean deleteByOccurence(int n) {
		int val=searchValue(n);
		if(val!=-1) {
			return deleteByPos(val);
		}return false;
	}
	@Override
	public String toString() {
		return "MyArray [arr=" + Arrays.toString(arr) + "]";
	}
	
}
