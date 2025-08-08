#pragma once
#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain {
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(std::string idea);
        Brain(const Brain& other);
        ~Brain();
        Brain& operator=(const Brain& other);
        
        // Getter and Setter methods
        const std::string& getIdea(size_t index) const;
        void setIdea(size_t index, const std::string& idea);
        void displayIdeas(size_t start = 0, size_t end = 5) const;
};

#endif