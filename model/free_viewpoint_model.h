/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright 2021 ETRI (Electronic and Telecommunication Research Institute) KOREA
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef FREE_VIEWPOINT_MODEL_H
#define FREE_VIEWPOINT_MODEL_H

#include "multiview-model.h"
#include "ns3/core-module.h"
#include "ns3/random-variable-stream.h"

namespace ns3 {

class Free_Viewpoint_Model : public MultiView_Model
{
public:
  Free_Viewpoint_Model();
  Free_Viewpoint_Model(const std::string free_viewpoint_file);

protected:
  int32_t InitViewpoint();
  int32_t GetNextViewpoint(const int64_t t_index);

private:
  Ptr<UniformRandomVariable> m_pUniRNG;
  Ptr<ExponentialRandomVariable> m_pExpRNG;
  std::vector <double> m_cumulativeProb;
  std::vector <double> m_avgDwellTime;
  int m_remDwellTime;
  int m_minDwellTime;
};
} // namespace ns3

#endif /* FREE_VIEWPOINT_MODEL_H */