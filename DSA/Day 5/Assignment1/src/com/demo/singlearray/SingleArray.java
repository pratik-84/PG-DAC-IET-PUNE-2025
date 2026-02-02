package com.demo.singlearray;

import java.util.ArrayList;
import java.util.Scanner;

public class SingleArray {
	Scanner sc=new Scanner(System.in);
	private int[] arr;
	int sz;


	public void accept() {
		
		System.out.println("enter size of array");
		sz=sc.nextInt();
arr= new int[sz];
		System.out.println("enter values in array");
		for(int i=0;i<sz;i++) {
			arr[i]=sc.nextInt();
		}
		
	}
	
	
	public void display() {
		for(int i=0;i<sz;i++) {
			System.out.print( arr[i]+" ");
	}
}
	
	
	public ArrayList<Integer> factOfPrime() {
		ArrayList<Integer> al=new ArrayList<>();
		
		for(int i=1;i<=sz;i++) {
			if(arr[i]%2==0) {
				fact(arr[i]);
				al.add(i);
			}
			else {
				System.out.println("no prime no in array");
			}
		}
		
		
		
		return al;
		
	}


	private int fact(int i) {
		int f=1;
		for(int j=1;j<sz;j++) {
			f=f*i;
		}
		return f;
	}
}
