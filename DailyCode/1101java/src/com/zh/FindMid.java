package com.zh;

import java.util.Scanner;

public class FindMid {
	@SuppressWarnings("resource")
	public static void main(String args[]){
		System.out.println("hello world!");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] product=new int[n];
		for(int i=0;i<n;i++)
		{
			product[i]=sc.nextInt();
		}
		//System.out.println(product.length);
		bubble(product);
		for(int i=0;i<product.length;i++)
			System.out.println(product[i]);
		findMid(product);
	}
	
	static void bubble(int[] product){
		for(int i=0;i<product.length-1;i++){
			for(int j=i+1;j<product.length;j++){
				if(product[i]>product[j]) 
					swap(product,i,j);
			}
		}
	}
	
	static void swap(int[] product,int i,int j){
		int temp;
		temp=product[i];
		product[i]=product[j];
		product[j]=temp;
	}
	
	static void findMid(int[] product){
		if(product.length%2==0)
			System.out.println(product[product.length/2-1]+product[product.length/2]);
		else
			System.out.println(product[product.length/2]);
	}
}
