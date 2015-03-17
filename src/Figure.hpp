/**
 * @file   Figure.hpp
 * @author  <nicolas@archimede>
 * @date   Wed Mar 18 00:27:19 2015
 * 
 * @brief  Describe the Figure structure
 * 
 * 
 */
#include <vector>
#include <iostream>
#include "Note.hpp" 

class Figure
{
private :
    struct WeightedNote : public Note
    {
        unsigned weight;
    };
private :
    std::vector<WeightedNote> notes;
public :
    using ConstIterator = std::vector<WeightedNote>::const_iterator;
    using Iterator = std::vector<WeightedNote>::iterator;
    bool check() const;
    void save(std::ostream& o) const;
    static Figure load(std::istream& i);
    static Figure randomInstance();
    std::ostream& operator<<(std::ostream& o) const;
    std::ostream& operator>>(std::istream& i);
    static Figure fromStream(std::istream& i);

    Figure() = default;
    template<typename Iterator>
    Figure(Iterator begin, Iterator end);
    Figure(const Figure&) = default;
    Figure(Figure&&) = default;
    Figure& operator=(const Figure&) = default;
    ~Figure() = default;


    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;
    unsigned nbNotes() const;

    void addNote(const Note& n, unsigned weight = 1);

    const WeightedNote& getNoteAtTime(const Fraction& t) const;
    Fraction getTotalDuration() const;

    std::vector<Fraction> getNotePercentage() const;
};