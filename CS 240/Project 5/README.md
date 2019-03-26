# Flight Scheduler

Compile with `make`

`./Flight.exe input.txt`

The user selects their itinerary objective, either 'any itinerary' or 'earliest arrival.'

Upon objective selection, the user is promtped to provide the following information:

Departure city - The city the user wishes to depart from

Destination city - The city the user wishes to travel to

Departure time - The latest possible time the user is willing to depart. 08:00pm departure time means any flight that leaves BEFORE 08:00pm is valid

Return time - The latest possible the time the user is willing to arrive back from the return trip. 02:00pm return time means any returning flight that arrives BEFORE 02:00pm is valid
	
To retrieve the maximum itinerary, the user would supply 11:59pm for their departure time and arrival time.
	
	Select your itinerary objective
	1. Any itinerary
	2. Earliest arrival
	3. Cheapest flight
	:1
	Provide the following trip constraints on a single line separated by spaces
	[Departure city] [Destination city] [Departure time] [Return time for the next day]
	:Boston Philadelphia 11:59pm 11:59pm

	Below lists every possible flight combination under the provided constraints

	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $228
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $238
	(DEPARTURE FLIGHT) Depart: Boston 6:44pm Arrive: Philadelphia 8:2pm (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $258
	(DEPARTURE FLIGHT) Depart: Boston 7:32pm Arrive: Philadelphia 8:45pm (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $242
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $236
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $246
	(DEPARTURE FLIGHT) Depart: Boston 6:44pm Arrive: Philadelphia 8:2pm (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $266
	(DEPARTURE FLIGHT) Depart: Boston 7:32pm Arrive: Philadelphia 8:45pm (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $250
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 3:24pm Arrive: Boston 5:20pm (TOTAL COST) $239
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 3:24pm Arrive: Boston 5:20pm (TOTAL COST) $249
	(DEPARTURE FLIGHT) Depart: Boston 6:44pm Arrive: Philadelphia 8:2pm (RETURN FLIGHT) Depart: Philadelphia 3:24pm Arrive: Boston 5:20pm (TOTAL COST) $269
	(DEPARTURE FLIGHT) Depart: Boston 7:32pm Arrive: Philadelphia 8:45pm (RETURN FLIGHT) Depart: Philadelphia 3:24pm Arrive: Boston 5:20pm (TOTAL COST) $253
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:2pm (TOTAL COST) $227
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:2pm (TOTAL COST) $237
	(DEPARTURE FLIGHT) Depart: Boston 6:44pm Arrive: Philadelphia 8:2pm (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:2pm (TOTAL COST) $257
	(DEPARTURE FLIGHT) Depart: Boston 7:32pm Arrive: Philadelphia 8:45pm (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:2pm (TOTAL COST) $241
		
As the departure time decreases, so does the itinerary size.
	
	Select your itinerary objective
	1. Any itinerary
	2. Earliest arrival
	3. Cheapest flight
	:1
	Provide the following trip constraints on a single line separated by spaces
	[Departure city] [Destination city] [Departure time] [Return time for the next day]
	:Boston Philadelphia 02:00pm 11:59pm
	
	Below lists every possible flight combination under the provided constraints

	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $228
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $238
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $236
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $246
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 3:24pm Arrive: Boston 5:20pm (TOTAL COST) $239
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 3:24pm Arrive: Boston 5:20pm (TOTAL COST) $249
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:2pm (TOTAL COST) $227
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:2pm (TOTAL COST) $237
	
Decreasing the return trip arrival time will also decrease the itinerary size.
	
	Select your itinerary objective
	1. Any itinerary
	2. Earliest arrival
	3. Cheapest flight
	:1
	Provide the following trip constraints on a single line separated by spaces
	[Departure city] [Destination city] [Departure time] [Return time for the next day]
	:Boston Philadelphia 02:00pm 02:00pm

	Below lists every possible flight combination under the provided constraints

	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $228
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 9:10am Arrive: Boston 11:14am (TOTAL COST) $238
	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $236
	(DEPARTURE FLIGHT) Depart: Boston 1:10pm Arrive: Philadelphia 2:14pm (RETURN FLIGHT) Depart: Philadelphia 11:5am Arrive: Boston 1:2pm (TOTAL COST) $246

Finding the cheapest flight uses the 'any itinerary' algorithm and selects the cheapest from the list
	
	Select your itinerary objective
	1. Any itinerary
	2. Earliest arrival
	3. Cheapest flight
	:3
	Provide the following trip constraints on a single line separated by spaces
	[Departure city] [Destination city] [Departure time] [Return time for the next day]
	:Boston Philadelphia 11:59pm 11:59pm

	Below lists every possible flight combination under the provided constraints

	(DEPARTURE FLIGHT) Depart: Boston 10:12am Arrive: Philadelphia 11:34am (RETURN FLIGHT) Depart: Philadelphia 6:44pm Arrive: Boston 8:02pm (TOTAL COST) $227

