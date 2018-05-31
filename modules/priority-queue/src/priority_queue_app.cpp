// Copyright 2018 Mezina Margarita

#include <iostream>
#include <exception>
#include <cstdlib>
#include <string>
#include <sstream>

#include "include/priority_queue_app.h"
#include "include/priority_queue.h"

PriorityQueueApp::PriorityQueueApp() : message_("") {}
void PriorityQueueApp::help(const char* appname, const char* message) {
	message_ =
		std::string(message) +
		"This is a priority queue application.\n\n" +
		"Please provide arguments in the following format:\n\n" +

		"  $ " + appname + " <amount of elements> " +
		" <array of element names> " + " <array of element priorities> " + 
		" <array of queue times> " + " <array of time working>\n\n" +

		"Where the first argument is non-negative integer, " +
		"array of element names is a sequence of non-repeating strings, " +
		"their lengths are less than 20, " +
		"their number is <amount of elements>, " +
		"array of element priorities is non-negative integers, " +
		"their number is <amount of elements>, " +
		"array of queue times is non-negative integers, " +
		"their number is <amount of elements> and " +
		"array of time working is non-negative integers, " +
		"their number is <amount of elements>\n";
}

bool PriorityQueueApp::validateNumberOfArguments(int argc, const char** argv) {
	if (argc == 1) {
		help(argv[0]);
		return false;
	}
	if (argc != (2 + atoi(argv[1]) * 4)) {
		help(argv[0],
			"ERROR: Should be 1 + 3*<amount of elements> arguments\n\n");
		return false;
	}
	return true;
}

int parseInt(const char* arg) {
	int value = std::stoi(std::string(arg));
	return value;
}

std::string PriorityQueueApp::operator()(int argc, const char** argv) {
	Arguments args;
	if (!validateNumberOfArguments(argc, argv)) {
		return message_;
	}
	try {
		args.n = parseInt(argv[1]);
		args.element_names = new std::string[args.n];
		args.element_priority = new int[args.n];
		args.element_time_start = new int[args.n];
		args.element_time_work = new int[args.n];
		for (int i = 0; i < args.n; ++i)
			args.element_names[i] = std::string(argv[2 + i]);
		for (int i = 0; i < args.n; ++i)
			args.element_priority[i] = parseInt(argv[2 + args.n + i]);
		for (int i = 0; i < args.n; ++i)
			args.element_time_start[i] = parseInt(argv[2 + args.n + i]);
		for (int i = 0; i < args.n; ++i)
			args.element_priority[i] = parseInt(argv[2 + 2*args.n + i]);
	}
	catch (std::string& str) {
		return str;
	}
	catch (std::exception& exc) {
		return
			std::string("Wrong format integer number or out of range");
	}
	try {
		PriorityQueue<int> pq;
		std::ostringstream stream;
		stream << "Priority Queue:\n";
		stream << "Number\tName elenent\tPriority element\tTime in queue\tTime working\n";
		for (int i = 0; i < args.n; ++i) {
			stream << i + 1 << "\t";
			stream << args.element_names[i] << "\t";
			stream << args.element_priority[i] << "\t";
			stream << args.element_time_start[i] << "\t";
			stream << args.element_time_work[i]<<"\n";
		}
		int finished_count = 0;
		int work_element = -1;
		int time_work = 0;
		int time = 0;
		while (finished_count != args.n) {
			time++;
			stream << "Im moment " << time << "\n";
			for (int i = 0; i < args.n; ++i) 
				if (args.element_time_start[i] == time) {
					stream << "\t" << args.element_names[i] << "go into queue\n";
					pq.Push(i, args.element_priority[i]);
				}
			
		}


		message_ = stream.str();
		return message_;
	}
	catch (std::exception& exc) {
		return std::string(exc.what());
	}
}
