package com.demo.stack;

public class MyStack {
	Node top;
	class Node{
		int data;
		Node next;
		public Node(int data) {
			super();
			this.data = data;
			this.next=null;
		}
		}
	public MyStack() {
		top=null;
		
	}
	public void pushNode(int val) {
		Node newnode=new Node(val);
		if(isEmpty()) {
			top=newnode;

		}
		else {
			newnode.next=top;
			top=newnode;
		}
	}
	private boolean isEmpty() {
		// TODO Auto-generated method stub
		return top==null;
	}
	
	public void pop() {
		if(!isEmpty()) {
			Node temp=top;
			top=top.next;
			temp.next=null;
		}
	}
	
	
	
}
