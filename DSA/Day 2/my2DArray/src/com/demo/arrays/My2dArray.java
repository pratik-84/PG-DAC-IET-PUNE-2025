package com.demo.arrays;

import java.util.Scanner;

public class My2dArray {
	private int [][] arr;

	public My2dArray() {
		arr=new int[3][3];
	}

	public My2dArray(int row,int column) {
		arr=new int[row][column];
	}
	
	public void acceptArr() {
		Scanner sc=new Scanner (System.in);
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[0].length;j++) {
				System.out.println("enter element of array in "+i+","+j);
				arr[i][j]=sc.nextInt();
			}
		}
	}
	
	public void displayArr() {
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[0].length;j++) {
				System.out.print(arr[i][j]+"    ");
			}
			System.out.println();
		}
		System.out.println("----------------------------");
	}
	
	public int[] sumRowWise() {
		int[] rowadd =new int[arr.length];
		for(int i=0;i<arr.length;i++) {
			for(int j=0;j<arr[0].length;j++) {
				rowadd[i]+=arr[i][j];
			}	
		}
		return rowadd;
	}
	
	public int[] sumColWise() {
		int[] coladd=new int[arr[0].length];
		for(int i=0;i<arr[0].length;i++) {
			for(int j=0;j<arr.length;j++) {
				coladd[i]+=arr[j][i];
			}
			
		}return coladd;
	}
	
	public int[][] add2Array(My2dArray ob1){
		if(this.arr.length==ob1.arr.length&&this.arr[0].length==ob1.arr[0].length) {
			int[][] sumarr=new int[arr.length][arr[0].length];
			for(int i=0;i<this.arr.length;i++) {
				for(int j=0;j<this.arr[0].length;j++) {
					sumarr[i][j]=this.arr[i][j]+ob1.arr[i][j];
				}
			}
			return sumarr;
		}
		return null;
	}
	
	public int[][] sub2Array(My2dArray ob1){
		if(this.arr.length==ob1.arr.length&&this.arr[0].length==ob1.arr[0].length) {
			int[][] subarr=new int[arr.length][arr[0].length];
			for(int i=0;i<arr.length;i++) {
				for(int j=0;j<arr[0].length;j++) {
					subarr[i][j]=this.arr[i][j]-ob1.arr[i][j];
				}
			}
			return subarr;
		}
		return null;
	}
	
	public void rowRotation(boolean flag,int num) {
		if(flag) {
			//upwards
			for(int cnt=0;cnt<num;cnt++) {
				int[] temp=arr[0];
				
				for(int i=0;i<arr.length-1;i++) {
					arr[i]=arr[i+1];
				}
				arr[arr.length-1]=temp;
			}
		}
		else{
			//downwards
			for(int cnt=0;cnt<num;cnt++) {
				int[] temp=arr[arr.length-1];
				
				for(int i=arr.length-1;i>0;i--) {
					arr[i]=arr[i-1];
				}
				arr[0]=temp;
			}
	    }
	}	
	
	public void columnRotation(boolean flag, int num) {
																			
	}
	
	
	
	public int[][] transpose(){
		int[][] temp= new int[arr[0].length][arr.length];
		for (int i=0;i<arr.length; i++) {
			for(int j=0;j<arr[0].length; j++) {
				temp[j][i]=arr[i][j];
			}
		}
		return temp;
	}
	
	public boolean issymmetric() {
		if(arr.length==arr[0].length) {
			for(int i=0;i<arr.length;i++) {
				for(int j=0;j<arr[0].length;j++) {
					if(arr[i][j] != arr[j][i])
						return false;
				}
			}
			return true;
					}
		return false;	
	}
	
	public boolean isIdenitity() {
		for(int i=0;i<arr.length;i++) {
			for(int j=0; j<arr[i].length; j++) {
				if(i==j && arr[i][j]!=1) {
					return false;
				}else if(i!=j && arr[i][j]!=0) {
					return false;
				}
			}
		}
		return true;
}
	
}