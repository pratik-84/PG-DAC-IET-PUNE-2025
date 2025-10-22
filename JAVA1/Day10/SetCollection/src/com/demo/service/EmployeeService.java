package com.demo.service;

import java.util.List;
import java.util.Set;

import com.demo.beans.Employee;

public interface EmployeeService {

	boolean addNewEmp();

	Set<Employee> displayAll();

	Employee serachById(int id);

	Set<Employee> searchByName(String nm);

	boolean updateSal(int id, double sal);

	boolean deleteId(int id);

	boolean deleteSal(double sal);

	Set<Employee> searchBySal(double sal);

	List<Employee> sortBySal();

	List<Employee> sortByName();

	Set<Employee> sortById();

}
