package com.demo.test;

import java.util.List;
import java.util.Scanner;
import java.util.Set;

import com.demo.beans.Employee;
import com.demo.service.EmployeeService;
import com.demo.service.EmployeeServiceImpl;

public class EmployeTestMnge {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		EmployeeService eservice =new EmployeeServiceImpl();
		int choice =0;
		do{
			System.out.println("1. add new employee\n 2. display all\n3. search by id");
			System.out.println("4. Search by name\n 5. update sal\n6. delete by id\n7. delete by salary\n");
			System.out.println("8. search by salary \n 9. sort by salary\n10. Sort By name\n 11. Sort By id\n12. exit\n choice: ");
			choice =sc.nextInt();
			switch (choice) {
			case 1->{
				boolean status=eservice.addNewEmp();
				if(status) {
					System.out.println("added");
				}
				else
					System.out.println("not added");
			}
			case 2->{
				Set<Employee> eset=eservice.displayAll();
				if(eset!=null) {
					eset.forEach(System.out::println);
				}
			}
			case 3->{
				System.out.println("enter id to find");
				int id=sc.nextInt();
				Employee e =eservice.serachById(id);
				if(e!=null) {
					System.out.println(e);
				}
				else {
					System.out.println("not found");
				}
			}
			case 4->{
				System.out.println("enter name");
				String nm=sc.next();
				Set<Employee> eset=eservice.searchByName(nm);
				if(eset!=null) {
					eset.forEach(System.out::println);
				}
				else {
					System.out.println("nto found");
				}
				
			}
			case 5->{
				System.out.println("enter id");
				int id=sc.nextInt();
				System.out.println("entre updates sal");
				double sal=sc.nextDouble();
				boolean status=eservice.updateSal(id,sal);
						if(status) {
							System.out.println("updated");
						}
						else {
							System.out.println("not found");
						}
				}
			case 6->{
				System.out.println("enter id");
				int id=sc.nextInt();
				boolean status=eservice.deleteId(id);
				if(status) {
					System.out.println("deleted");
				}
				else {
					System.out.println("not found");
				}
			}
			case 7->{
				System.out.println("enter sal");
				double sal=sc.nextDouble();
				boolean status=eservice.deleteSal(sal);
				if(status) {
					System.out.println("deleted");
				}
				else {
					System.out.println("not found");
				}
			}
			case 8->{
				System.out.println("enter sal");
				double sal=sc.nextDouble();
				Set <Employee> eset=eservice.searchBySal(sal);
				if(eset!=null) {
					eset.forEach(System.out::println);
				}
			}
			case 9->{
				List<Employee> temp=eservice.sortBySal();
				temp.forEach(System.out::println);
			}
			case 10->{
				List<Employee> telp=eservice.sortByName();
				telp.forEach(System.out::println);
			}
			case 11->{
				Set<Employee> temp=eservice.sortById();
				temp.forEach(System.out::println);
			}
			case 12->{
				sc.close();
				System.out.println("thnakyou for visiting");
			}
			default->{
				System.out.println("wrong choice");
			}
			}
		}
		while(choice !=12);
	}
	

}
