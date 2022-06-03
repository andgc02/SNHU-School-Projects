package com.gamingroom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * A simple class to hold information about a game
 * 
 * <p>
 * Notice the overloaded constructor that requires
 * an id and name to be passed when creating.
 * Also note that no mutators (setters) defined so
 * these values cannot be changed once a game is
 * created.
 * </p>
 * 
 * @author coce@snhu.edu
 *
 */


public class Game extends Entity {

	//list of teams
	private List<Team> teams = new ArrayList<Team>();

	/**
	 * Constructor with an identifier and name
	 */
	public Game(long id, String name) {
		super(id, name); //access attributes from base class
	}
	
	/**
	 * Iterator pattern to add unique teams to list
	 * @param name
	 * @return
	 */
	public Team addTeam(String name) {
		
		//default team instance
		Team team = null;
		
		//Iterator
		Iterator<Team> teamsIterator = teams.iterator();
		
		while (teamsIterator.hasNext()) {
			
			Team teamInstance = teamsIterator.next();
			
			//Return current team if it already exists, else create new unique instance
			if (teamInstance.getName().equalsIgnoreCase(name)) {
				
				team = teamInstance;
			} else {
				teams.add(team);
			}
		}
		
		return team;
	}
	
	@Override
	public String toString() {
		
		return "Game [id=" + super.getId() + ", name=" + super.getName() + "]";
	}

}
