#ifndef VALHALLA_LOKI_SEARCH_H_
#define VALHALLA_LOKI_SEARCH_H_

#include <valhalla/baldr/location.h>
#include <valhalla/baldr/pathlocation.h>
#include <valhalla/baldr/graphreader.h>
#include <valhalla/baldr/directededge.h>
#include <valhalla/sif/dynamiccost.h>

#include <functional>

namespace valhalla{
namespace loki{

/**
 * A callable element which returns true if an edge should be
 * filtered out of the correlated set and false if the edge is usable
 *
 * TODO: remove the filtering of transit edges when they get proper
 * opposing edges added to the graph
 */
const sif::EdgeFilter PassThroughFilter = [](const baldr::DirectedEdge* edge){ return edge->trans_up() || edge->trans_down() || edge->IsTransitLine(); };

/**
 * Find an location within the route network given an input location
 * same tiled route data and a search strategy
 *
 * @param location  the position which needs to be correlated to the route network
 * @param reader    and object used to access tiled route data TODO: switch this out for a proper cache
 * @param filter    a function/functor to be used in the rejection of edges. defaults to a pass through filter
 * @return pathLocation  the correlated data with in the tile that matches the input
 */
baldr::PathLocation Search(const baldr::Location& location, baldr::GraphReader& reader, sif::EdgeFilter filter = PassThroughFilter);

}
}

#endif  // VALHALLA_LOKI_SEARCH_H_
