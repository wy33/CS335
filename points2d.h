// --> William Yang
// Class Points2D is a container for a sequence of 2D points

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

    // Class has 2 member variables:
    // @sequence_: a pointer to an array of 2D points (represented by a std::array of size 2).
    // @size_: a size_t variable to keep track of the amount of 2D points in sequence_.
    template<typename Object>
    class Points2D {
    public:
        // Zero-parameter constructor.
        // Set size to 0.
        Points2D() : sequence_(nullptr), size_(0) {
        }

        // Copy-constructor.
        Points2D(const Points2D& rhs) : size_(rhs.size_), sequence_(nullptr) {
            if(size_ != 0) {
                sequence_ = new std::array<Object, 2>[size_];
                for (size_t i = 0; i < size_; i++) {
                    sequence_[i][0] = rhs.sequence_[i][0];
                    sequence_[i][1] = rhs.sequence_[i][1];
                }
            }
        }

        // Copy-assignment.
        Points2D& operator=(const Points2D& rhs) {
            Points2D copy = rhs;
            std::swap(*this, copy);
            return *this;
        }

        // Move-constructor.
        Points2D(Points2D&& rhs) : sequence_(rhs.sequence_), size_(rhs.size_) {
            rhs.sequence_ = nullptr;
            rhs.size_ = 0;
        }

        // Move-assignment.
        Points2D& operator=(Points2D&& rhs) {
            std::swap(sequence_, rhs.sequence_);
            std::swap(size_, rhs.size_);
            return *this;
        }

        ~Points2D() {
            if (size_ != 0) {
                delete[] sequence_;
                sequence_ = nullptr;
            }
        }

        // End of big-five.

        // One parameter constructor.
        Points2D(const std::array<Object, 2>& item) {
            size_ = 1;
            sequence_ = new std::array<Object, 2>[size_];
            sequence_[0][0] = item[0];
            sequence_[0][1] = item[1];
        }

        size_t size() const {
            return size_;
        }

        // @location: an index to a location in the sequence.
        // @returns the point at @location.
        // const version.
        // abort() if out-of-range.
        const std::array<Object, 2>& operator[](size_t location) const {
            if (location < 0 || location >= size_) {
                std::cerr << "ERROR" << std::endl;
                abort();
            }
            return sequence_[location];
        }

        //  @c1: A sequence.
        //  @c2: A second sequence.
        //  @return their sum. If the sequences are not of the same size, append the
        //    result with the remaining part of the larger sequence.
        friend Points2D operator+(const Points2D& c1, const Points2D& c2) {
            Points2D<Object> result;
            if (c1.size_ == 0 && c2.size_ == 0)
                return result;

            // lesser_sequence is used to determine when addition between Points2D c1 and c2 ends
            // due to the possibility that the 2 sequences aren't equal in size.
            size_t lesser_sequence;
            if (c1.size_ < c2.size_) {
                lesser_sequence = c1.size_;
                result.size_ = c2.size_;
                result.sequence_ = new std::array<Object, 2>[c2.size_];
            }
            else {
                lesser_sequence = c2.size_;
                result.size_ = c1.size_;
                result.sequence_ = new std::array<Object, 2>[c1.size_];
            }

            for (size_t i = 0; i < lesser_sequence; i++) {
                result.sequence_[i][0] = c1.sequence_[i][0] + c2.sequence_[i][0];
                result.sequence_[i][1] = c1.sequence_[i][1] + c2.sequence_[i][1];
            }

            if (c1.size_ < c2.size_) {
                for (size_t i = lesser_sequence; i < c2.size_; i++) {
                    result.sequence_[i][0] = c2.sequence_[i][0];
                    result.sequence_[i][1] = c2.sequence_[i][1];
                }
            }
            else {
                for (size_t i = lesser_sequence; i < c1.size_; i++) {
                    result.sequence_[i][0] = c1.sequence_[i][0];
                    result.sequence_[i][1] = c1.sequence_[i][1];
                }
            }

            return result;
        }

        // Overloading the << operator.
        // Output format: (0, 1) (2, 3) (4, 5) etc.
        friend std::ostream& operator<<(std::ostream& out, const Points2D& some_points) {
            if (some_points.size_ != 0) {
                for (size_t i = 0; i < some_points.size_; i++) {
                    out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1] << ")";
                    if (i != some_points.size_ - 1)
                        out << " ";
                }
            }
            else {
                out << "()";
            }

            return out;
        }

        // Overloading the >> operator.
        // Read a chain from an input stream (e.g., standard input).
        friend std::istream& operator>>(std::istream& in, Points2D& some_points) {
            size_t number_of_points;
            in >> number_of_points;
            if (in.fail()) {
                std::cerr << "ERROR" << std::endl;
                abort();
            }

            if (number_of_points == 0)
                return in;

            if (some_points.size_ == 0) {
                some_points.sequence_ = new std::array<Object, 2>[number_of_points];
                for (size_t i = 0; i < number_of_points; i++) {
                    in >> some_points.sequence_[i][0] >> some_points.sequence_[i][1];
                    if (in.fail()) {
                        std::cerr << "ERROR" << std::endl;
                        abort();
                    }
                }
                some_points.size_ = number_of_points;
            }
            // Points2D some_points not empty, reallocate memory.
            else {
                size_t newSize = number_of_points + some_points.size_;
                std::array<Object, 2>* newSequence = new std::array<Object, 2>[newSize];
                for (size_t i = 0; i < some_points.size_; i++) {
                    newSequence[i][0] = some_points.sequence_[i][0];
                    newSequence[i][1] = some_points.sequence_[i][1];
                }
                for (size_t i = some_points.size_; i < newSize; i++) {
                    in >> newSequence[i][0] >> newSequence[i][1];
                    if (in.fail()) {
                        std::cerr << "ERROR" << std::endl;
                        abort();
                    }
                }

                delete[] some_points.sequence_;
                some_points.sequence_ = newSequence;
                some_points.size_ = newSize;
            }

            return in;
        }

    private:
        // Sequence of points.
        std::array<Object, 2>* sequence_;
        // Size of sequence.
        size_t size_;
    };

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
