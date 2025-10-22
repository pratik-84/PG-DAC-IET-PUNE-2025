package com.demo.dao;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

import com.demo.beans.Employee;

public class EmployeeDaoImpl implements EmployeeDao{
	static Set<Employee> eset;
	static {
		eset=new HashSet<>();
		eset.add(new Employee(101,"max",12345,LocalDate.of(2024, 12, 03)));
		eset.add(new Employee(103,"sam",34345,LocalDate.of(2012, 02, 23)));
		eset.add(new Employee(102,"fns",65345,LocalDate.of(2020, 06, 13)));
		

	}
	@Override
	public boolean addNewEmp(Employee e) {
		// TODO Auto-generated method stub
		return eset.add(e);
	}
	@Override
	public Set<Employee> displayAll() {
		// TODO Auto-generated method stub
		return eset;
	}
	@Override
	public Employee findById(int id) {
		for(Employee e:eset){
			if(e.getEid()==id) {
				return e;
			}
				
		}
		return null;
		
//		Optional<Employee> od=eset.stream()
//				.filter(e-> e.getEid()==id);//error
//										
//		return e;
	}
	@Override
	public Set<Employee> searchByName(String nm) {
		// TODO Auto-generated method stub
		 Set <Employee> temp =new HashSet<>();
		for(Employee e:eset) {
			if(e.getEnm().equals(nm)) {
				temp.add(e); 
			}
		}
		return null;
	}
	@Override
	public boolean updateSal(int id, double sal) {
		for(Employee e:eset) {
			if(e.getEid()==id) {
				e.setSal(sal);
				return true;
			}
		}
		return false;
	}
	@Override
	public boolean deleteById(int id) {
		return eset.remove(new Employee(id));
	}
	@Override
	public boolean deleteBySal(double sal) {
		// TODO Auto-generated method stub
		return eset.removeIf(e->e.getSal()>sal);
	}
	@Override
	public Set<Employee> searchBySal(double sal) {
		Set<Employee> temp=new HashSet<>();
		for(Employee e:eset) {
			if(e.getSal()>sal)
				temp.add(e);
//				return temp;
		}
		return temp;
		
	}
	@Override
	public List<Employee> sortBySal() {
		// TODO Auto-generated method stub
		Comparator<Employee> csal=(o1,o2)->{
			return (int)(o1.getSal()-o2.getSal());
		};
		List <Employee> temp =new ArrayList<>();
		for(Employee e:eset) {
			temp.add(e);
		}
		temp.sort(csal);
		return temp;
	}
	@Override
	public List<Employee> sortByname() {
		// TODO Auto-generated method stub
		Comparator<Employee> temp=(o1,o2)->{
			return o1.getEnm().compareTo(o2.getEnm());
		};
		List<Employee> elist=new ArrayList<>();
		for(Employee e:eset) {
			elist.add(e);
		}
		elist.sort(temp);
		return elist;
	}
	@Override
	public Set<Employee> sortById() {
		// TODO Auto-generated method stub
		Set<Employee> temp=new HashSet();
		for(Employee e:eset) {
			temp.add(e);
		}
		
		return temp;
	}
	

}
