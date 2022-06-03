package com.gamingroom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * A singleton service for the game engine
 * 
 * @author coce@snhu.edu
 */
public class GameService {

	/**
	 * A list of the active games
	 */
	private static List<Game> games = new ArrayList<Game>();

	/*
	 * Holds the next game identifier
	 */
	private static long nextGameId = 1;
	
	/*
	 * Holds the next player identifier
	 */
	private static long nextPlayerId = 1;
	
	/*
	 * Holds the next team identifier
	 */
	private static long nextTeamId = 1;

	//Private tracking of GameService existence
	private static GameService service = null;
	
	//Constructor
	private GameService() {
	}
	
	/**
	 * Singleton Pattern to check instance of GameService
	 * @return
	 */
	public static GameService getInstance() {
		
		//create new instance if GameService is not instantiated
		if (service == null) {
			service = new GameService();
		} else {
			System.out.println("Game Service instance already exists.");
		}
		//returns only one instance of GameService
		return service;
	}

	/**
	 * Construct a new game instance
	 * 
	 * @param name the unique name of the game
	 * @return the game instance (new or existing)
	 */
	public Game addGame(String name) {

		// a local game instance
		Game game = null;

		//Iterator pattern for Game
		Iterator<Game> gamesIterator = games.iterator();
		
		//Iterate through list of games
		while (gamesIterator.hasNext()) {
			
			//Set gameInstance to the following item
			Game gameInstance = gamesIterator.next();
			
			
			if (gameInstance.getName().equalsIgnoreCase(name)) {
				return gameInstance;
			}
		}
		
		// if found, simply return the existing instance

		// if not found, make a new game instance and add to list of games
		if (game == null) {
			game = new Game(nextGameId++, name);
			games.add(game);
		}

		// return the new/existing game instance to the caller
		return game;
	}

	/**
	 * Returns the game instance at the specified index.
	 * <p>
	 * Scope is package/local for testing purposes.
	 * </p>
	 * @param index index position in the list to return
	 * @return requested game instance
	 */
	Game getGame(int index) {
		return games.get(index);
	}
	
	/**
	 * Returns the game instance with the specified id.
	 * 
	 * @param id unique identifier of game to search for
	 * @return requested game instance
	 */
	public Game getGame(long id) {

		// a local game instance
		Game game = null;

		//Iterator pattern
		Iterator <Game> gamesIterator = games.iterator();
		
		//Iterate through list of games
		while (gamesIterator.hasNext()) {
			
			Game gameInstance = gamesIterator.next();
			
			if (gameInstance.getId() == id) {
				return gameInstance;
			}
		}
		
		// if found, simply assign that instance to the local variable

		return game;
	}

	/**
	 * Returns the game instance with the specified name.
	 * 
	 * @param name unique name of game to search for
	 * @return requested game instance
	 */
	public Game getGame(String name) {

		// a local game instance
		Game game = null;
		
		//Iterator Pattern
		Iterator<Game> gamesIterator = games.iterator();
		
		while (gamesIterator.hasNext()) {
			Game gameInstance = gamesIterator.next();
			
			if (gameInstance.getName().equalsIgnoreCase(name)) {
				game = gameInstance;
			}
		}
		// if found, simply assign that instance to the local variable

		return game;
	}

	/**
	 * Returns the number of games currently active
	 * 
	 * @return the number of games currently active
	 */
	public int getGameCount() {
		return games.size();
	}
	
	public long getNextPlayerId() {
		return nextPlayerId;
	}
	
	public long getNextTeamId() {
		return nextTeamId;
	}
}
