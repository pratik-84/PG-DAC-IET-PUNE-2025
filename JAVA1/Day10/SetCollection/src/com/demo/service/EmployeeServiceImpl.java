package com.demo.service;

import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

import com.demo.beans.Employee;
import com.demo.dao.EmployeeDao;
import com.demo.dao.EmployeeDaoImpl;

public class EmployeeServiceImpl implements EmployeeService{
	private EmployeeDao edao ;

	public EmployeeServiceImpl() {
		super();
		this.edao=new EmployeeDaoImpl();
	}

	@Override
	public boolean addNewEmp() {
		Scanner sc=new Scanner(System.in);
		System.out.println("etner id");
		int eid=sc.nextInt();
		System.out.println("enter name");
		String enm=sc.next();
		System.out.println("enter sal");
		double sal=sc.nextDouble();
		System.out.println("enter date in (dd/MM/yyyy");
		String dt=sc.next();
		LocalDate ldt =  LocalDate.parse(dt, DateTimeFormatter.ofPattern("dd/MM/yyyy"));
		Employee e=new Employee(eid,enm,sal,ldt);
		
		return edao.addNewEmp(e);
	}

	@Override
	public Set<Employee> displayAll() {
		// TODO Auto-generated method stub
		return edao.displayAll();
	}

	@Override
	public Employee serachById(int id) {
		// TODO Auto-generated method stub
		return edao.findById(id);
	}

	@Override
	public Set<Employee> searchByName(String nm) {
		// TODO Auto-generated method stub
		return edao.searchByName(nm);
	}

	@Override
	public boolean updateSal(int id, double sal) {
		// TODO Auto-generated method stub
		return edao.updateSal(id,sal);
	}

	@Override
	public boolean deleteId(int id) {
		// TODO Auto-generated method stub
		return edao.deleteById(id);
	}

	@Override
	public boolean deleteSal(double sal) {
		// TODO Auto-generated method stub
		return edao.deleteBySal(sal);
	}

	@Override
	public Set<Employee> searchBySal(double sal) {
		// TODO Auto-generated method stub
		return edao.searchBySal(sal);
	}

	@Override
	public List<Employee> sortBySal() {
		// TODO Auto-generated method stub
		return edao.sortBySal();
	}

	@Override
	public List<Employee> sortByName() {
		// TODO Auto-generated method stub
		return edao.sortByname();
	}

	@Override
	public Set<Employee> sortById() {
		// TODO Auto-generated method stub
		return edao.sortById();
	}
	
	
}
