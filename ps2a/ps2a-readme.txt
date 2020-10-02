/**********************************************************************
 *  N-Body Simulation ps2a-readme.txt template
 **********************************************************************/

Name: Stephanie La
Hours to complete assignment: 7 hours

/**********************************************************************
 *  Briefly discuss the assignment itself and what you accomplished.
 **********************************************************************/
This assignment reads in input from a text file and displays a window 
of planets based on the file.

  /**********************************************************************
 *  Discuss one or more key algorithms, data structures, or 
 *  OO designs that were central to the assignment.
 **********************************************************************/
I used a vector of CelestialBody pointers to loop through an empty object
and fill it with each planet and draw it as well. It was a member of the
Universe class I made.

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Describe if and how do you used the smart pointers 
 *  Include code excerpts.
 **********************************************************************/
I did not use smart pointers in ps2a. 
With an empty object, I looped through and dereferenced the planets to give
 them a radius and window size relative to their coordinates. planets[i] is a 
pointer to the object, and *planets[i] was a dereference back to the object itself.
for (int i = 0; i < num_of_planets; i++) {
		planets.push_back(new CelestialBody()); //allocate space for a CelestialBody, and pushes allocated pointer into vector
		planets[i]->set_radius(r); //planets[i] is a pointer to the object
		planets[i]->set_window(window);
		in >> *planets[i];
	}

I had to also loop through and draw each of the planets, where the target was planets.
for (int i = 0; i < numberOfPlanets; i++) {
		target.draw(*planets.at(i), states); //draw each of the planets 
	}

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
SFML website, youtube, and stack overflow help.

/**********************************************************************
 *  Describe any serious problems you encountered.                    
 **********************************************************************/
Document was very wordy and difficult to follow.

/**********************************************************************
 *  List any other comments here.                                     
 **********************************************************************/
