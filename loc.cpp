#include "loc.h"

ostream& operator <<(ostream& outs, const loc& stuff){
    outs<<"("<<stuff.row<<","<<stuff.col<<")\n";
    return outs;
}
