package com.gamingroom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * A simple class to hold information about a team
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a team is
 * created.
 * </p>
 * @author coce@snhu.edu
 *
 */
public class Team extends Entity{

	//List of teams
	private List<Player> players = new ArrayList<Player>();
	
	/*
	 * Constructor with an identifier and name
	 */
	public Team(long id, String name) {
		super(id, name);
	}
	
	/**
	 * Add unique players to team using iterator
	 * @param name
	 * @return
	 */
	public Player addPlayer(String name) {
		
		Player player = null;
		
		Iterator<Player> playersIterator = players.iterator();
		
		while (playersIterator.hasNext()) {
			
			Player playerInstance = playersIterator.next();
			
			if (playerInstance.getName().equalsIgnoreCase(name)) {
				
				player = playerInstance;
			} else {
				players.add(player);
			}
		}
		
		return player;
	}

	@Override
	public String toString() {
		return "Team [id=" + super.getId() + ", name=" + super.getName() + "]";
	}
}
