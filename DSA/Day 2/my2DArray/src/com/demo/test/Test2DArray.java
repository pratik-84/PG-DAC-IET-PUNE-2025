package com.demo.test;

import com.demo.arrays.My2dArray;

public class Test2DArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		My2dArray ob=new My2dArray();
		My2dArray ob1=new My2dArray(3,3);

		ob.acceptArr();
		ob.displayArr();
//		ob1.acceptArr();
//		int[] rowwise=ob.sumRowWise();
//		display(rowwise);
		
//		int[] colwise=ob.sumColWise();
//		display(colwise);
		
//		int [][] arr=ob.sub2Array(ob1);
//		if(arr!=null) {
//			display(arr);
//		}
//		else {
//			System.out.println("dimenssions not match");
//		}
		
		ob.rowRotation(true, 1);
		ob.displayArr();
		
		if(ob.issymmetric()) {
			System.out.println("symmetric hai");
		}
		else {
			System.out.println("nhi hai");
		}
		
		if(ob1.isIdenitity()) {
			System.out.println("(iden)tities matrix");
		}else {
			System.out.println("not Idenitity matrix");
		}
		
		
		
		
		
		
		
		
		

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
		private static void display(int[] rowwise) {
			for(int i=0;i<rowwise.length;i++) {
				System.out.print(rowwise[i]+"  ");
			}
		}
		private static void display(int[][] arr) {
				for(int i=0;i<arr.length;i++){
					for(int j=0;j<arr[0].length;j++) {
						System.out.print(arr[i][j]+"\t");
					}
					System.out.println();
				}
				
			
		

}
}
