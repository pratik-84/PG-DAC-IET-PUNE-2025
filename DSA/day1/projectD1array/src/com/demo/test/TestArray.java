package com.demo.test;
import java.util.Arrays;
import com.demo.array.MyArray;

public class TestArray {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		MyArray ob=new MyArray();
		System.out.println(ob.getCapacity()+" is lenght of array");
		System.out.println(ob);
		ob.add(4);
		ob.add(9);
		ob.add(5);
		ob.add(7);
		ob.add(6);
		ob.add(9);
		ob.add(1);
		ob.addAtIndex(1,2);
		System.out.println(ob);
//		System.out.println(ob.searchValue(7));
//		ob.deleteByPos(6);
//		System.out.println(ob);
//		ob.deleteByOccurence(1);
		System.out.println(ob);

		
	}

}
