package com.zh;

import java.util.Scanner;

public class FindTheNum {
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int[] num=new int[n];
		for(int i=0;i<n;i++){
			num[i]=sc.nextInt();
		}
		sort_(num);
		System.out.println("###");
		int nn=sc.nextInt();
		int[] findN=new int[nn];
		for(int i=0;i<nn;i++){
			findN[i]=sc.nextInt();
		}
		print(num,findN);
	}
	
	static void sort_(int[] num)
	{
		for(int i=0;i<num.length-1;i++)
			for(int j=i+1;j<num.length;j++)
				if(num[i]>num[j])
					swap(num,i,j);
	}
	
	static void swap(int[] num,int i,int j){
		int temp;
		temp=num[i];
		num[i]=num[j];
		num[j]=temp;
	}
	
	static void print(int[] num,int[] findN){
		for(int i=0;i<findN.length;i++)
			System.out.println(num[findN[i]-1]);
	}
}
