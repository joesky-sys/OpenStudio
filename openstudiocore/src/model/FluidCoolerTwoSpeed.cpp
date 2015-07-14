/**********************************************************************
 *  Copyright (c) 2008-2015, Alliance for Sustainable Energy.
 *  All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 **********************************************************************/

#include "FluidCoolerTwoSpeed.hpp"
#include "FluidCoolerTwoSpeed_Impl.hpp"

#include "Node.hpp"
#include "Node_Impl.hpp"

#include <utilities/idd/IddEnums.hxx>
#include <utilities/idd/IddFactory.hxx>
#include <utilities/idd/OS_FluidCooler_TwoSpeed_FieldEnums.hxx>

#include "../utilities/core/Assert.hpp"
#include "../utilities/units/Unit.hpp"

namespace openstudio {
namespace model {

namespace detail {

  FluidCoolerTwoSpeed_Impl::FluidCoolerTwoSpeed_Impl(const IdfObject& idfObject,
                                                     Model_Impl* model,
                                                     bool keepHandle)
    : StraightComponent_Impl(idfObject,model,keepHandle)
  {
    OS_ASSERT(idfObject.iddObject().type() == FluidCoolerTwoSpeed::iddObjectType());
  }

  FluidCoolerTwoSpeed_Impl::FluidCoolerTwoSpeed_Impl(const openstudio::detail::WorkspaceObject_Impl& other,
                                                     Model_Impl* model,
                                                     bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {
    OS_ASSERT(other.iddObject().type() == FluidCoolerTwoSpeed::iddObjectType());
  }

  FluidCoolerTwoSpeed_Impl::FluidCoolerTwoSpeed_Impl(const FluidCoolerTwoSpeed_Impl& other,
                                                     Model_Impl* model,
                                                     bool keepHandle)
    : StraightComponent_Impl(other,model,keepHandle)
  {}

  const std::vector<std::string>& FluidCoolerTwoSpeed_Impl::outputVariableNames() const
  {
    static std::vector<std::string> result;
    if (result.empty()){
    }
    return result;
  }

  IddObjectType FluidCoolerTwoSpeed_Impl::iddObjectType() const {
    return FluidCoolerTwoSpeed::iddObjectType();
  }

  unsigned FluidCoolerTwoSpeed_Impl::inletPort()
  {
    return  OS_FluidCooler_TwoSpeedFields::WaterInletNode;
  }

  unsigned FluidCoolerTwoSpeed_Impl::outletPort()
  {
    return  OS_FluidCooler_TwoSpeedFields::WaterOutletNode;
  }

  std::string FluidCoolerTwoSpeed_Impl::performanceInputMethod() const {
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::PerformanceInputMethod,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::highFanSpeedUfactorTimesAreaValue() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::HighFanSpeedUfactorTimesAreaValue,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isHighFanSpeedUfactorTimesAreaValueAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::HighFanSpeedUfactorTimesAreaValue, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::lowFanSpeedUfactorTimesAreaValue() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedUfactorTimesAreaValue,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isLowFanSpeedUfactorTimesAreaValueAutocalculated() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::LowFanSpeedUfactorTimesAreaValue, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autocalculate");
    }
    return result;
  }

  double FluidCoolerTwoSpeed_Impl::lowFanSpeedUFactorTimesAreaSizingFactor() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedUFactorTimesAreaSizingFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  double FluidCoolerTwoSpeed_Impl::highSpeedNominalCapacity() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::HighSpeedNominalCapacity,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::lowSpeedNominalCapacity() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::LowSpeedNominalCapacity,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isLowSpeedNominalCapacityAutocalculated() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::LowSpeedNominalCapacity, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autocalculate");
    }
    return result;
  }

  double FluidCoolerTwoSpeed_Impl::lowSpeedNominalCapacitySizingFactor() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::LowSpeedNominalCapacitySizingFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  double FluidCoolerTwoSpeed_Impl::designEnteringWaterTemperature() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::DesignEnteringWaterTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  double FluidCoolerTwoSpeed_Impl::designEnteringAirTemperature() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::DesignEnteringAirTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  double FluidCoolerTwoSpeed_Impl::designEnteringAirWetbulbTemperature() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::DesignEnteringAirWetbulbTemperature,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::designWaterFlowRate() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::DesignWaterFlowRate,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isDesignWaterFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::DesignWaterFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::highFanSpeedAirFlowRate() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::HighFanSpeedAirFlowRate,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isHighFanSpeedAirFlowRateAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::HighFanSpeedAirFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::highFanSpeedFanPower() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::HighFanSpeedFanPower,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isHighFanSpeedFanPowerAutosized() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::HighFanSpeedFanPower, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autosize");
    }
    return result;
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::lowFanSpeedAirFlowRate() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedAirFlowRate,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isLowFanSpeedAirFlowRateAutocalculated() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::LowFanSpeedAirFlowRate, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autocalculate");
    }
    return result;
  }

  double FluidCoolerTwoSpeed_Impl::lowFanSpeedAirFlowRateSizingFactor() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedAirFlowRateSizingFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<double> FluidCoolerTwoSpeed_Impl::lowFanSpeedFanPower() const {
    return getDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedFanPower,true);
  }

  bool FluidCoolerTwoSpeed_Impl::isLowFanSpeedFanPowerAutocalculated() const {
    bool result = false;
    boost::optional<std::string> value = getString(OS_FluidCooler_TwoSpeedFields::LowFanSpeedFanPower, true);
    if (value) {
      result = openstudio::istringEqual(value.get(), "autocalculate");
    }
    return result;
  }

  double FluidCoolerTwoSpeed_Impl::lowFanSpeedFanPowerSizingFactor() const {
    boost::optional<double> value = getDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedFanPowerSizingFactor,true);
    OS_ASSERT(value);
    return value.get();
  }

  boost::optional<Node> FluidCoolerTwoSpeed_Impl::outdoorAirInletNode() const {
    return getObject<ModelObject>().getModelObjectTarget<Node>(OS_FluidCooler_TwoSpeedFields::OutdoorAirInletNode);
  }

  bool FluidCoolerTwoSpeed_Impl::setPerformanceInputMethod(std::string performanceInputMethod) {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::PerformanceInputMethod, performanceInputMethod);
    return result;
  }

  bool FluidCoolerTwoSpeed_Impl::setHighFanSpeedUfactorTimesAreaValue(boost::optional<double> highFanSpeedUfactorTimesAreaValue) {
    bool result(false);
    if (highFanSpeedUfactorTimesAreaValue) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::HighFanSpeedUfactorTimesAreaValue, highFanSpeedUfactorTimesAreaValue.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autosizeHighFanSpeedUfactorTimesAreaValue() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::HighFanSpeedUfactorTimesAreaValue, "autosize");
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setLowFanSpeedUfactorTimesAreaValue(boost::optional<double> lowFanSpeedUfactorTimesAreaValue) {
    bool result(false);
    if (lowFanSpeedUfactorTimesAreaValue) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedUfactorTimesAreaValue, lowFanSpeedUfactorTimesAreaValue.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autocalculateLowFanSpeedUfactorTimesAreaValue() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::LowFanSpeedUfactorTimesAreaValue, "autocalculate");
    OS_ASSERT(result);
  }

  void FluidCoolerTwoSpeed_Impl::setLowFanSpeedUFactorTimesAreaSizingFactor(double lowFanSpeedUFactorTimesAreaSizingFactor) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedUFactorTimesAreaSizingFactor, lowFanSpeedUFactorTimesAreaSizingFactor);
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setHighSpeedNominalCapacity(double highSpeedNominalCapacity) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::HighSpeedNominalCapacity, highSpeedNominalCapacity);
    return result;
  }

  bool FluidCoolerTwoSpeed_Impl::setLowSpeedNominalCapacity(boost::optional<double> lowSpeedNominalCapacity) {
    bool result(false);
    if (lowSpeedNominalCapacity) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::LowSpeedNominalCapacity, lowSpeedNominalCapacity.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autocalculateLowSpeedNominalCapacity() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::LowSpeedNominalCapacity, "autocalculate");
    OS_ASSERT(result);
  }

  void FluidCoolerTwoSpeed_Impl::setLowSpeedNominalCapacitySizingFactor(double lowSpeedNominalCapacitySizingFactor) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::LowSpeedNominalCapacitySizingFactor, lowSpeedNominalCapacitySizingFactor);
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setDesignEnteringWaterTemperature(double designEnteringWaterTemperature) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::DesignEnteringWaterTemperature, designEnteringWaterTemperature);
    return result;
  }

  bool FluidCoolerTwoSpeed_Impl::setDesignEnteringAirTemperature(double designEnteringAirTemperature) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::DesignEnteringAirTemperature, designEnteringAirTemperature);
    return result;
  }

  bool FluidCoolerTwoSpeed_Impl::setDesignEnteringAirWetbulbTemperature(double designEnteringAirWetbulbTemperature) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::DesignEnteringAirWetbulbTemperature, designEnteringAirWetbulbTemperature);
    return result;
  }

  bool FluidCoolerTwoSpeed_Impl::setDesignWaterFlowRate(boost::optional<double> designWaterFlowRate) {
    bool result(false);
    if (designWaterFlowRate) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::DesignWaterFlowRate, designWaterFlowRate.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autosizeDesignWaterFlowRate() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::DesignWaterFlowRate, "autosize");
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setHighFanSpeedAirFlowRate(boost::optional<double> highFanSpeedAirFlowRate) {
    bool result(false);
    if (highFanSpeedAirFlowRate) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::HighFanSpeedAirFlowRate, highFanSpeedAirFlowRate.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autosizeHighFanSpeedAirFlowRate() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::HighFanSpeedAirFlowRate, "autosize");
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setHighFanSpeedFanPower(boost::optional<double> highFanSpeedFanPower) {
    bool result(false);
    if (highFanSpeedFanPower) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::HighFanSpeedFanPower, highFanSpeedFanPower.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autosizeHighFanSpeedFanPower() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::HighFanSpeedFanPower, "autosize");
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setLowFanSpeedAirFlowRate(boost::optional<double> lowFanSpeedAirFlowRate) {
    bool result(false);
    if (lowFanSpeedAirFlowRate) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedAirFlowRate, lowFanSpeedAirFlowRate.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autocalculateLowFanSpeedAirFlowRate() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::LowFanSpeedAirFlowRate, "autocalculate");
    OS_ASSERT(result);
  }

  void FluidCoolerTwoSpeed_Impl::setLowFanSpeedAirFlowRateSizingFactor(double lowFanSpeedAirFlowRateSizingFactor) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedAirFlowRateSizingFactor, lowFanSpeedAirFlowRateSizingFactor);
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setLowFanSpeedFanPower(boost::optional<double> lowFanSpeedFanPower) {
    bool result(false);
    if (lowFanSpeedFanPower) {
      result = setDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedFanPower, lowFanSpeedFanPower.get());
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::autocalculateLowFanSpeedFanPower() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::LowFanSpeedFanPower, "autocalculate");
    OS_ASSERT(result);
  }

  void FluidCoolerTwoSpeed_Impl::setLowFanSpeedFanPowerSizingFactor(double lowFanSpeedFanPowerSizingFactor) {
    bool result = setDouble(OS_FluidCooler_TwoSpeedFields::LowFanSpeedFanPowerSizingFactor, lowFanSpeedFanPowerSizingFactor);
    OS_ASSERT(result);
  }

  bool FluidCoolerTwoSpeed_Impl::setOutdoorAirInletNode(const boost::optional<Node>& node) {
    bool result(false);
    if (node) {
      result = setPointer(OS_FluidCooler_TwoSpeedFields::OutdoorAirInletNode, node.get().handle());
    }
    else {
      resetOutdoorAirInletNode();
      result = true;
    }
    return result;
  }

  void FluidCoolerTwoSpeed_Impl::resetOutdoorAirInletNode() {
    bool result = setString(OS_FluidCooler_TwoSpeedFields::OutdoorAirInletNode, "");
    OS_ASSERT(result);
  }

} // detail

FluidCoolerTwoSpeed::FluidCoolerTwoSpeed(const Model& model)
  : StraightComponent(FluidCoolerTwoSpeed::iddObjectType(),model)
{
  OS_ASSERT(getImpl<detail::FluidCoolerTwoSpeed_Impl>());

  bool ok = true;
  // ok = setHandle();
  OS_ASSERT(ok);
   ok = setPerformanceInputMethod("NominalCapacity"); // UFactorTimesAreaAndDesignWaterFlowRate, NominalCapacity
  OS_ASSERT(ok);
  ok = setHighFanSpeedUfactorTimesAreaValue(0.1);
  OS_ASSERT(ok);
  ok = setLowFanSpeedUfactorTimesAreaValue(0.1);
  OS_ASSERT(ok);
  setLowFanSpeedUFactorTimesAreaSizingFactor(1.0);
  OS_ASSERT(lowFanSpeedUFactorTimesAreaSizingFactor() == 1.0);
  ok = setHighSpeedNominalCapacity(0.1);
  OS_ASSERT(ok);
  ok = setLowSpeedNominalCapacity(0.1);
  OS_ASSERT(ok);
  setLowSpeedNominalCapacitySizingFactor(1.0);
  OS_ASSERT(lowSpeedNominalCapacitySizingFactor() == 1.0);
  ok = setDesignEnteringWaterTemperature(0.1);
  OS_ASSERT(ok);
  ok = setDesignEnteringAirTemperature(0.1);
  OS_ASSERT(ok);
  ok = setDesignEnteringAirWetbulbTemperature(0.1);
  OS_ASSERT(ok);
  ok = setDesignWaterFlowRate(0.1);
  OS_ASSERT(ok);
  ok = setHighFanSpeedAirFlowRate(0.1);
  OS_ASSERT(ok);
  ok = setHighFanSpeedFanPower(0.1);
  OS_ASSERT(ok);
  ok = setLowFanSpeedAirFlowRate(0.1);
  OS_ASSERT(ok);
  setLowFanSpeedAirFlowRateSizingFactor(0.1);
  ok = setLowFanSpeedFanPower(0.1);
  OS_ASSERT(ok);
  setLowFanSpeedFanPowerSizingFactor(0.1);
}

IddObjectType FluidCoolerTwoSpeed::iddObjectType() {
  return IddObjectType(IddObjectType::OS_FluidCooler_TwoSpeed);
}

std::vector<std::string> FluidCoolerTwoSpeed::performanceInputMethodValues() {
  return getIddKeyNames(IddFactory::instance().getObject(iddObjectType()).get(),
                        OS_FluidCooler_TwoSpeedFields::PerformanceInputMethod);
}

std::string FluidCoolerTwoSpeed::performanceInputMethod() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->performanceInputMethod();
}

boost::optional<double> FluidCoolerTwoSpeed::highFanSpeedUfactorTimesAreaValue() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->highFanSpeedUfactorTimesAreaValue();
}

bool FluidCoolerTwoSpeed::isHighFanSpeedUfactorTimesAreaValueAutosized() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isHighFanSpeedUfactorTimesAreaValueAutosized();
}

boost::optional<double> FluidCoolerTwoSpeed::lowFanSpeedUfactorTimesAreaValue() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowFanSpeedUfactorTimesAreaValue();
}

bool FluidCoolerTwoSpeed::isLowFanSpeedUfactorTimesAreaValueAutocalculated() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isLowFanSpeedUfactorTimesAreaValueAutocalculated();
}

double FluidCoolerTwoSpeed::lowFanSpeedUFactorTimesAreaSizingFactor() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowFanSpeedUFactorTimesAreaSizingFactor();
}

double FluidCoolerTwoSpeed::highSpeedNominalCapacity() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->highSpeedNominalCapacity();
}

boost::optional<double> FluidCoolerTwoSpeed::lowSpeedNominalCapacity() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowSpeedNominalCapacity();
}

bool FluidCoolerTwoSpeed::isLowSpeedNominalCapacityAutocalculated() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isLowSpeedNominalCapacityAutocalculated();
}

double FluidCoolerTwoSpeed::lowSpeedNominalCapacitySizingFactor() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowSpeedNominalCapacitySizingFactor();
}

double FluidCoolerTwoSpeed::designEnteringWaterTemperature() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->designEnteringWaterTemperature();
}

double FluidCoolerTwoSpeed::designEnteringAirTemperature() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->designEnteringAirTemperature();
}

double FluidCoolerTwoSpeed::designEnteringAirWetbulbTemperature() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->designEnteringAirWetbulbTemperature();
}

boost::optional<double> FluidCoolerTwoSpeed::designWaterFlowRate() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->designWaterFlowRate();
}

bool FluidCoolerTwoSpeed::isDesignWaterFlowRateAutosized() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isDesignWaterFlowRateAutosized();
}

boost::optional<double> FluidCoolerTwoSpeed::highFanSpeedAirFlowRate() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->highFanSpeedAirFlowRate();
}

bool FluidCoolerTwoSpeed::isHighFanSpeedAirFlowRateAutosized() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isHighFanSpeedAirFlowRateAutosized();
}

boost::optional<double> FluidCoolerTwoSpeed::highFanSpeedFanPower() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->highFanSpeedFanPower();
}

bool FluidCoolerTwoSpeed::isHighFanSpeedFanPowerAutosized() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isHighFanSpeedFanPowerAutosized();
}

boost::optional<double> FluidCoolerTwoSpeed::lowFanSpeedAirFlowRate() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowFanSpeedAirFlowRate();
}

bool FluidCoolerTwoSpeed::isLowFanSpeedAirFlowRateAutocalculated() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isLowFanSpeedAirFlowRateAutocalculated();
}

double FluidCoolerTwoSpeed::lowFanSpeedAirFlowRateSizingFactor() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowFanSpeedAirFlowRateSizingFactor();
}

boost::optional<double> FluidCoolerTwoSpeed::lowFanSpeedFanPower() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowFanSpeedFanPower();
}

bool FluidCoolerTwoSpeed::isLowFanSpeedFanPowerAutocalculated() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->isLowFanSpeedFanPowerAutocalculated();
}

double FluidCoolerTwoSpeed::lowFanSpeedFanPowerSizingFactor() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->lowFanSpeedFanPowerSizingFactor();
}

boost::optional<Node> FluidCoolerTwoSpeed::outdoorAirInletNode() const {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->outdoorAirInletNode();
}

bool FluidCoolerTwoSpeed::setPerformanceInputMethod(std::string performanceInputMethod) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setPerformanceInputMethod(performanceInputMethod);
}

bool FluidCoolerTwoSpeed::setHighFanSpeedUfactorTimesAreaValue(double highFanSpeedUfactorTimesAreaValue) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setHighFanSpeedUfactorTimesAreaValue(highFanSpeedUfactorTimesAreaValue);
}

void FluidCoolerTwoSpeed::autosizeHighFanSpeedUfactorTimesAreaValue() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autosizeHighFanSpeedUfactorTimesAreaValue();
}

bool FluidCoolerTwoSpeed::setLowFanSpeedUfactorTimesAreaValue(double lowFanSpeedUfactorTimesAreaValue) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowFanSpeedUfactorTimesAreaValue(lowFanSpeedUfactorTimesAreaValue);
}

void FluidCoolerTwoSpeed::autocalculateLowFanSpeedUfactorTimesAreaValue() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autocalculateLowFanSpeedUfactorTimesAreaValue();
}

void FluidCoolerTwoSpeed::setLowFanSpeedUFactorTimesAreaSizingFactor(double lowFanSpeedUFactorTimesAreaSizingFactor) {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowFanSpeedUFactorTimesAreaSizingFactor(lowFanSpeedUFactorTimesAreaSizingFactor);
}

bool FluidCoolerTwoSpeed::setHighSpeedNominalCapacity(double highSpeedNominalCapacity) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setHighSpeedNominalCapacity(highSpeedNominalCapacity);
}

bool FluidCoolerTwoSpeed::setLowSpeedNominalCapacity(double lowSpeedNominalCapacity) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowSpeedNominalCapacity(lowSpeedNominalCapacity);
}

void FluidCoolerTwoSpeed::autocalculateLowSpeedNominalCapacity() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autocalculateLowSpeedNominalCapacity();
}

void FluidCoolerTwoSpeed::setLowSpeedNominalCapacitySizingFactor(double lowSpeedNominalCapacitySizingFactor) {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowSpeedNominalCapacitySizingFactor(lowSpeedNominalCapacitySizingFactor);
}

bool FluidCoolerTwoSpeed::setDesignEnteringWaterTemperature(double designEnteringWaterTemperature) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setDesignEnteringWaterTemperature(designEnteringWaterTemperature);
}

bool FluidCoolerTwoSpeed::setDesignEnteringAirTemperature(double designEnteringAirTemperature) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setDesignEnteringAirTemperature(designEnteringAirTemperature);
}

bool FluidCoolerTwoSpeed::setDesignEnteringAirWetbulbTemperature(double designEnteringAirWetbulbTemperature) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setDesignEnteringAirWetbulbTemperature(designEnteringAirWetbulbTemperature);
}

bool FluidCoolerTwoSpeed::setDesignWaterFlowRate(double designWaterFlowRate) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setDesignWaterFlowRate(designWaterFlowRate);
}

void FluidCoolerTwoSpeed::autosizeDesignWaterFlowRate() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autosizeDesignWaterFlowRate();
}

bool FluidCoolerTwoSpeed::setHighFanSpeedAirFlowRate(double highFanSpeedAirFlowRate) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setHighFanSpeedAirFlowRate(highFanSpeedAirFlowRate);
}

void FluidCoolerTwoSpeed::autosizeHighFanSpeedAirFlowRate() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autosizeHighFanSpeedAirFlowRate();
}

bool FluidCoolerTwoSpeed::setHighFanSpeedFanPower(double highFanSpeedFanPower) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setHighFanSpeedFanPower(highFanSpeedFanPower);
}

void FluidCoolerTwoSpeed::autosizeHighFanSpeedFanPower() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autosizeHighFanSpeedFanPower();
}

bool FluidCoolerTwoSpeed::setLowFanSpeedAirFlowRate(double lowFanSpeedAirFlowRate) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowFanSpeedAirFlowRate(lowFanSpeedAirFlowRate);
}

void FluidCoolerTwoSpeed::autocalculateLowFanSpeedAirFlowRate() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autocalculateLowFanSpeedAirFlowRate();
}

void FluidCoolerTwoSpeed::setLowFanSpeedAirFlowRateSizingFactor(double lowFanSpeedAirFlowRateSizingFactor) {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowFanSpeedAirFlowRateSizingFactor(lowFanSpeedAirFlowRateSizingFactor);
}

bool FluidCoolerTwoSpeed::setLowFanSpeedFanPower(double lowFanSpeedFanPower) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowFanSpeedFanPower(lowFanSpeedFanPower);
}

void FluidCoolerTwoSpeed::autocalculateLowFanSpeedFanPower() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->autocalculateLowFanSpeedFanPower();
}

void FluidCoolerTwoSpeed::setLowFanSpeedFanPowerSizingFactor(double lowFanSpeedFanPowerSizingFactor) {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setLowFanSpeedFanPowerSizingFactor(lowFanSpeedFanPowerSizingFactor);
}

bool FluidCoolerTwoSpeed::setOutdoorAirInletNode(const Node& node) {
  return getImpl<detail::FluidCoolerTwoSpeed_Impl>()->setOutdoorAirInletNode(node);
}

void FluidCoolerTwoSpeed::resetOutdoorAirInletNode() {
  getImpl<detail::FluidCoolerTwoSpeed_Impl>()->resetOutdoorAirInletNode();
}

/// @cond
FluidCoolerTwoSpeed::FluidCoolerTwoSpeed(std::shared_ptr<detail::FluidCoolerTwoSpeed_Impl> impl)
  : StraightComponent(impl)
{}
/// @endcond

} // model
} // openstudio
