package com.gamingroom;

public class Entity {
	
	//attributes
	private long id;
	private String name;
	
	//Constructors
	private Entity() {
		
	}
	
	public Entity(long id, String name) {
		this();
		this.id = id;
		this.name = name;
	}
	
	public String toString() {
		return "Entity [id= " + id + ", name= " + name + "]";
	}
	
	//Accessors
	public long getId() {
		return id;
	}
	
	public String getName() {
		return name;
	}
}