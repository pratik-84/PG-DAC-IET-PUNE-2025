package com.demo.dao;

import java.util.List;
import java.util.Set;

import com.demo.beans.Employee;

public interface EmployeeDao {

	boolean addNewEmp(Employee e);

	Set<Employee> displayAll();

	Employee findById(int id);

	Set<Employee> searchByName(String nm);

	boolean updateSal(int id, double sal);

	boolean deleteById(int id);

	boolean deleteBySal(double sal);

	Set<Employee> searchBySal(double sal);

	List<Employee> sortBySal();

	List<Employee> sortByname();

	Set<Employee> sortById();
	
}
