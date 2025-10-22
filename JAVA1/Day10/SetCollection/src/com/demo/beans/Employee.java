package com.demo.beans;

import java.time.LocalDate;
import java.util.Objects;

public class Employee implements Comparable <Employee>{
	private int eid;
	private	String enm;
	private double sal;
	private LocalDate ldt;
	
	public Employee() {
		super();
	}
	
	public Employee(int eid) {
		super();
		this.eid=eid;
	}

	
	@Override
	public int hashCode() {
		return eid;
	}

	@Override
	public boolean equals(Object obj) {
		System.out.println("in equals method " +this.eid +"-----"+((Employee)obj).eid );
		
		return this.eid==((Employee)obj).eid;
	}

	public Employee(int eid, String enm, double sal, LocalDate ldt) {
		super();
		this.eid = eid;
		this.enm = enm;
		this.sal = sal;
		this.ldt = ldt;
	}
	
	@Override
	public String toString() {
		return "Employee [eid=" + eid + ", enm=" + enm + ", sal=" + sal + ", ldt=" + ldt + "]";
	}

	public int getEid() {
		return eid;
	}

	public void setEid(int eid) {
		this.eid = eid;
	}

	public String getEnm() {
		return enm;
	}

	public void setEnm(String enm) {
		this.enm = enm;
	}

	public double getSal() {
		return sal;
	}

	public void setSal(double sal) {
		this.sal = sal;
	}

	public LocalDate getLdt() {
		return ldt;
	}

	public void setLdt(LocalDate ldt) {
		this.ldt = ldt;
	}

	@Override
	public int compareTo(Employee o) {
		System.out.println("in compareTo method "+this.eid+"-----"+o.eid);
		return this.eid-o.eid;
	}
	
}
